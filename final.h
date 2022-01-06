#include <string>
#include <iostream>
#include <vector>


//Node class so stacks and queues can be implemented using linked lists
class Node {
    public:
        //Contains data of type string and a pointer to the next Node
        std::string data;
        Node* next;

        Node();
        Node(std::string info);
};

class Stack{

    public:
    //Has a Node pointing to the top of the stack
    Node* top;
    Stack();

    //Functions
    void push(Node* ptr);
    Node* pop();
    bool isempty();
    void showLastMeal();

};

class Queue{

    public:
    //Has two Nodes, one pointing to the front of the queue and another 
    //pointing to the rear end
    Node* front = NULL;
    Node* rear = NULL;
    Queue();
    
    //Functions
    void enqueue(Node* ptr);
    void dequeue();
    bool isempty();
    void showNextMeal();
    Node* getTopMeal();
};
