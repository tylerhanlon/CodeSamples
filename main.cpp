#include <iostream>
#include <vector>
#include "final.h"


int main(){

//Creates an empty stack, queue, and vector
    Stack myStack;
    Queue myQueue;
    std::vector<std::string> foodlist;


    std::cout << "Welcome to our MealPrep Application!" << std::endl;

    std::string response = "";

    //Will accept input from user until they choose to end the program
    while(response != "6"){


    response = "";
    std::cout << std::endl;
    //Outputs options and prompts user to select one
    std::cout << "MAKE A SELECTION: " << std::endl;
    std::cout << "Press [1] to enter meal into planned meals queue." << std::endl;
    std::cout << "Press [2] to log the next meal in your queue as eaten." << std::endl;
    std::cout << "Press [3] to see your most recently eaten meal." << std::endl;
    std::cout << "Press [4] to view what meal is planned next in your queue." << std::endl;
    std::cout << "Press [5] to view/edit your entire planned meals queue." << std::endl;
    std::cout << "Press [6] to end the program." << std::endl;
    std::cin >> response;
    std::cout << std::endl;

    if(response == "1"){
    //1 will call the enqueue function, adding a meal to the queue
        std::string mealName = "";
        std::cout << "Enter the meal to be added!" << std::endl;
        std::cin >> mealName;
        //Creates a new Node w/ data set to the inputted meal name
        Node* newNode = new Node(mealName);
        std::cout << mealName << " has been added to your Meal Plan!" << std::endl;
        myQueue.enqueue(newNode);
        //Adds the food item to the vector so it is available to be edited
        foodlist.push_back(newNode->data);
    }

    else if(response == "2"){
        if(myQueue.isempty() == true){
            std::cout << "Looks like you don't have any meals planned to log!" << std::endl;
        }
        else{
        //Gets the top meal from the queue so it can be used to push the
        //data from the Node into the stack
        Node* meal = myQueue.getTopMeal();
        std::cout << meal->data << " has been marked as eaten and removed from your plan!" << std::endl;
        myQueue.dequeue();
        myStack.push(meal);
        //This will erase the logged food item from the vector
        foodlist.erase(foodlist.begin());
        }
    }

    else if(response == "3"){
        if(myStack.isempty() == true){
            std::cout << "Looks like there are no previous meals logged to view!" << std::endl;
        }
        else{
            //Will show the top of the stack to the user
        myStack.showLastMeal();
    }
    }

   else if(response == "4"){
        if(myQueue.isempty() == true){
            std::cout << "Looks like there aren't any meals planned!" << std::endl;
        }
        else{
            //Will show the meal at the front of the queue
            myQueue.showNextMeal();
        }
    }

      else if(response == "5"){
        if(foodlist.empty() == true){
            std::cout << "No food inputed.";
        }
        else{
            //Loop to print the vector to the standard output
        for(int i = 0; i < foodlist.size(); i++){
            std::cout << (i + 1) << ". " << foodlist[i] << std::endl;
        }

        std::string response4 = "";

        while(response4 != "2"){
        std::cout << std::endl;
        std::cout << "PLEASE MAKE A SELECTION: " << std::endl;
        std::cout << "Press [1] if you would like to edit a meal" << std::endl;
        std::cout << "Press [2] if you would like to go back to the main menu" << std::endl;
        std::cout << std::endl;


        std::cin >> response4;

        if(response4 == "1"){
            //Prompts the user for idx of the item to edit
            std::string response3 = "";
            int foodNum = 0;
            std::cout << "Enter the number for the item you would like to edit" << std::endl;
            std::cin >> foodNum;

            while(foodNum > foodlist.size()){
                std::cout << "INVALID INPUT, ENTER AGAIN: " << std::endl;
                foodNum = 0;
                std::cin >> foodNum;
            }


            std::cout << std::endl;

            std::cout << "You have selected to edit " << foodlist[foodNum - 1] << std::endl;
            std::cout << std::endl;
            std::cout << "Enter 1 if you would like to delete the item" << std::endl;
            std::cout << "Enter 2 if you would like to edit the item" << std::endl;
            std::cin >> response3;

            if(response3 == "1"){
                //Erases the item from the array
                foodlist.erase(foodlist.begin() + (foodNum-1));
            }
            else if(response3 == "2"){
                std::string newFood = "";
                std::cout << "Please enter what you would like to change: " << foodlist[foodNum -1] << " to" << std::endl;
                std::cin >> newFood;
                std::cout << std::endl;
                //Replaces the item in the vector with the new one inputted by the user
                std::cout << foodlist[foodNum - 1] << " has been replaced with " << newFood << std::endl;
                foodlist[foodNum - 1] = newFood;

            }

            //Code to empty and refill the queue with Nodes w/ correct data
            while(myQueue.isempty() != true){
                    myQueue.dequeue();
                }
                for(int i = 0; i < foodlist.size(); i++){
                    Node* newestNode = new Node(foodlist[i]);
                    myQueue.enqueue(newestNode);
                }

        }
        else if(response4 != "2"){
            std::cout << "Looks like you have made an invalid selection!" <<std::endl;
            std::cout << "Please review the options and select again!" <<std::endl;
            std::cout << std::endl;
        }
        }
    }
   }

   else if(response == "6"){
       //Ends the program
        std::cout << "Thank you for using our program. Goodbye!" << std::endl;
    }

    else{
        //Asks the user for a new suggestion if theirs is invalid
            std::cout << "Looks like you have made an invalid selection!" <<std::endl;
            std::cout << "Please review the options and select again!" <<std::endl;
            std::cout << std::endl;
    }

}
    return 0;
}
