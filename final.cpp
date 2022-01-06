#include "final.h"
#include <iostream>
#include <vector>


//Constructor node
Node::Node(){
    data = "";
    next = NULL;
}


Node::Node(std::string info){
    //Can create a node w/ inputted data 
    data = info;
    next = NULL;
}

Stack::Stack(){
    //Default sets top to NULL upon creation of a stack
    top = NULL;
}

void Stack::push(Node* ptr){
    //Creates a temp node and sets it to top
    Node* temp = top;
    //Sets top equal to the inputted value
    top = ptr;
    //Sets the next part of ptr Node to the new top (temp)
    ptr->next = temp;
    //sets top Node equal to the new ptr 
    top = ptr;
}

//Removes the top value from the stack 
Node* Stack::pop(){
    //Temp node set to top 
    Node* temp = top;
    if(isempty() == false){
        //Sets top to next and removes it 
    top = top->next;
    return temp;
    }
    else{
    std::cout << "Looks like there is nothing logged in you meal history!";
    return temp;
    }
}

bool Stack::isempty(){
    //Can tell if the stack is empty by looking at if the top NOde is NULL
    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
}

void Stack::showLastMeal(){
    if(isempty() == false){
        //Will cout the data part of the top Node of the stack
        std::cout << "Your most recently eaten meal was " << top->data << std::endl;
    }
}

//Queue constructor
Queue::Queue(){
    //defaults front and rear Nodes to NULL
    Node* front = NULL;
    Node* rear = NULL;
}


bool Queue::isempty(){
    //Can tell if the queue is empty if the rear and front are both NULL
    if(rear == NULL && front == NULL){
        return true;
    }
    else{
        return false;
    }
}

void Queue::enqueue(Node* ptr){
    //If queue is empty set both front and rear to the inputted Node
     if(rear == NULL){
         front = ptr;
         rear = ptr;
         return;
     }
     //If not empty will set the next part of the rear Node to the 
     //inputted Node ptr then set rear to ptr 
     else{
        rear->next = ptr;
        rear = ptr;
     }
}


void Queue::dequeue(){
    //Will create a new temp Node 
    Node* temp = new Node();
if(isempty() == true){
    std::cout << "Looks like you don't have anymore meals in your plan!";
    return;
}

else if(front == rear){
    //If there is one item in the queue it will just set both rear and front 
    //to NULL
    temp = front;
    front = NULL;
    rear = NULL;
}
else{
    //Will set temp to front and set front equal to the next thing in the 
    //queue
    temp = front;
    front = front->next;
}
}



void Queue::showNextMeal(){
    //Outputs data part of front Node
        std::cout << "The next meal planned is " << front->data << std::endl;
}

Node* Queue::getTopMeal(){
    //This function returns the front Node of the queue so it can be used
    //by other functions
    if(isempty() == true){
        std::cout << "There are no planned meals inputted!" << std::endl;
        return 0;
    }
    else{
      return front;
    }
}

