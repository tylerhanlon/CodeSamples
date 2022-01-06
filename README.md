# CodeSamples
This repository consists of various projects I have completed over the course of my coding career.

Nickolas Psikakos, Tyler Hanlon, Gabriel Badolato
=================================================

*PROGRAM*:
The purpose of this program is for it to be a meal tracker in
which a user can use the interactive menu to log what they plan to eat
during a given day, and then log each meal in the order they entered
them as eaten. Other features include seeing what is next to eat, and
an option to view the entire list of items you have inserted to eat.
This also comes with a feature to edit the name of any items you
have already entered incase of a typo, or you ate something else.

--------------------------------------------------------------------

*INSTRUCTIONS*:
The instructions for this program are very simple. It is a user
driven program, where the user is prompted with six different choices.
The user would then enter their option of choice and navigate through.

IF ENTERING A SPACE FOR MEALS THAT ARE TWO OR MORE WORDS, BE SURE
TO USE AN UNDERSCORE ("_") BETWEEN EACH WORD RATHER THAN A SPACE.

--------------------------------------------------------------------

*DESIGN OVERVIEW/DATA STRUCTURES USED*:

-QUEUE-: We utilized a linked list to create the queue.
The purpose of using the queue is for adding meals to
the "planned" section of meals to eat. This is because a queue works
as a first in first out structure, so the first meal entered will
be marked as eaten once the user logs the next item in the queue.
When a user enters a meal by pressing 1, the food is enqueued into the
queue. This is taken as a string of characters. Once a food is logged as
eaten, the head node is dequeued, and the meal next in the queue
becomes the head and each node after takes the previous node's place.
The time complexity of enque and dequeue are very efficient as they are
both O(1), as no loops are used. In the case of editting your planned list
the queue is cleared, and refilled by the editted dynamic array that
contains all foods entered into the queue that have not been marked as eaten.
Overall, the queue is the perfect data structure for planning the meals
in the order to be eaten, as once a meal is eaten it is removed from
the top of the queue, as dequeue always works from removing the head
node.

-STACK-: We also utilized a linked list to create the stack.
The stack was used for the logging of meals eaten, as once a user presses
2 on the selection screen, the meal is dequeued from the queue, and
then pushed onto the stack. The user can then press 3 to view what
the last meal was that is on the top of the stack, which also
serves as a peak function. A stack works as a first in, last out
function. This makes it a perfect choice for its use to view the most
recently logged eaten meal, because it's tail node is what is viewed first.
The push function has a time complexity of O(1) similar to the queue,
but with the order the meals are logged, from least to most recent
the stack is the better option for viewing. The peak function is also
O(1), as there are no loops involved and pressing 4 just returns
the most recently added item in the stack. Items are never poped from
the stack as once something has been marked as eaten, it is not removed.


-LINKED LIST-: The data stored in the queue of planned meals and
in the stack of eaten meals are implemented using a linked list.
The stack and queue both hold nodes with each node pointing to the
next node in the linked list. In each function relating to the
stack and queue it should be noted that everything is done
using a linked list, with each node containing a string consisting
of the meal name and a pointer to the next node in the list. We
decided to use linked lists to implement the queues and stacks
because it was not necessary for us to use more memory than needed
if the user wasn't going to request to do so. Linked lists are more
efficient than arrays and allow the data to be stored w/ more
efficient memory usage, and also allow insertion and deletion
to be completed more quickly as well. Insertion to the end
of the linked list has a time complexity of O(1), as opposed
to the O(n) time complexity that an array uses for insertion.
Since the queue is the only thing affected when the user
is originally inputting their meal plan, it made sense
to implement this and the stack using a linked list rather
than an array.


-DYNAMIC ARRAYS-:
We used dynamic arrays in our program so we could give the user the option
to edit and remove things that they had previously inputted.
Dynamic arrays worked well for this because it gives easy access to
everything entered as well as it provides the opportunity to edit the data.
With dynamic arrays, we are able to edit a meal entered if there is a typo
or if the meal was changed. This wouldnt be an easy task with the other data
structures due to how they are accessed. The time compleity for push_back, begin(),
empty(), and size() is constant O(1) and the complexities for insert and erase
are linear O(n). However, this is an efficient solution for giving the user the
option to edit data by its specific index within the array.

--------------------------------------------------------------------

*POTENTIAL BUGS*:
While testing we have only found one bug with our program
which is the issue of entering spaces when entering a meal. The
solution we used is described in the instructions section.


--------------------------------------------------------------------

*CODE OVERVIEW*:
Our program contains three files:
1. final.h
2. final.cpp
3. main.cpp

####

To begin we will explain our header file:

Our header file contains three classes:
    Node class
    Queue class
    Stack Class

Every object of type Node contains a meal name (data) of type string, along
with a pointer called next. This is because we implemented our stacks and
queues using a linked list, so each node would need a pointer to the next
object in the queue or stack.

Our queue class contains Node objects for both the front and rear of the queue,
so each end can be kept track of. We then have a cvariety of functions
that we used in our program such as enqueue, dequeue, isempty, showNextMeal,
and getTopMeal. These functions will be further explained in the final.cpp
section of the README

The stack class is straightforward and contains a Node object pointing to the
top of the stack. This class includes functions such as push, pop, isempty,
and showLastMeal


####

The next file is the final.cpp file containing our function definitions:

We have constructors for each of our class objects. The Node constructor
can take in a string of data and will set the next ptr to NULL by default.
The stack constructor simply sets the top Node* to NULL. The queue constructor
sets both the front and rear Node ptrs to NULL.

Next I will briefly describe each function:

stack::push -> this is a void function that takes in a Node* as a parameter.
It then creates a temporary Node* which it sets equal to the top Node, and
then sets the top equal to the inputted Node*. It then sets the new top's
next ptr to the temp Node (old top).

stack::pop -> This function returns a Node* with the value that is
at the top of the stack. First a temp Node is created which is set
equal to the current top. Then, it checks if the stack is empty
and if it is not empty it will set top equal to the value at the memory location
pointed to by its next ptr. Then it returns the temporary value.

stack::isempty -> Just checks if top has a value stored and returns false
if so and true if top = NULL

stack::showLastMeal -> outputs the data part of the Node top to the standard
output as long as the stack is not empty

Queue::enqueue -> void function takes in a Node*. Checks if rear is NULL
and if so it will set the front and the rear both equal to the parameter.
If rear is not NULL then it will set the next part of the rear Node equal
to the parameter and set the new rear to the parameter.

Queue::dequeue -> void function that creates a temp new Node. Checks if empty
and if not then checks if front == rear (one element in queue). If there
is one element it just sets both front and rear to NULL. If there is more
than one element it will set the temp node equal to the front Node, and
will then set the front equal to the next part of the front Node.

Queue::isempty -> Boolean function that checks to see if both front and rear
are set to NULL. If so the function returns true, if not it will return false.

Queue::showNextMeal -> This will just output the data part of the front Node
of the queue

Queue::getTopMeal -> This will return the front Node of the queue


####

The final file in the program is our main.cpp:

This file is where the functions are called and the user input is read in
through the standard input. Upon compiling the program, an empty stack, queue, and
vector are created. The suer is prompted to select a number from the menu.

There are many if statements which will perform different actions based on the
input fed in by the user:

*Pressing 1 will take a string from the standard input, create a Node using
that data, and enqueue it to the queue. It will also add it to the vector
so it can be edited if need be.

*Pressing 2 will dequeue the first inputted meal from the queue, and will push it
to the stack of eaten/logged meals. This allows the most recently eaten meal
to be easily shown to the user. Doing so will also remove the meal from the
vector of meals that can be edited.

*Pressing 3 will show the data part of the top Node of the stack, which will
be the most recently logged/eaten meal from the user.

*Pressing 4 will call the showNextMeal function and it will output to the
standard output the meal which is currently at the front of the Planned Meals
queue

*Pressing 5 will output the dynamic array containing all inputted meals
that have not yet been logged as eaten. The user then has the choice to
edit a meal. The user can delete a meal or edit it. Once the user has
edited a meal, the queue is erased and is re-filled with Nodes containing
the new data from the dynamic  in the correct order.

*Pressing 6 will end the program for the user.

--------------------------------------------------------------------

*TOPIC OVERVIEW*:
Our project covers mastery in four different topics which include
Stacks, Queues, Linked Lists, and Dynamic Arrays. We demonstrate  mastery
in each of these topics by using each of them when their certain properties
best suited the data structure needed. We describe why we used each data struture
above in our design overview. Stacks and queues are both implemented
as linked lists, made up of nodes containing data with pointers to the next node.
These data structures are both used in aspects of the program that are efficient
and appropriate to their access types (FIFO and LIFO), and allow quick and
efficient outputting of data to the user based on their input to the program.
We also created a dynamic array, which allows the user to edit and remove data
by indexing it at any time in the program.
