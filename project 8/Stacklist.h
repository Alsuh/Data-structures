#include <iostream>
using namespace std;
class Stack{
public:
    //precondition : none 
    //postcondition : sets first to nothing
    Stack();
    //precondition: none
    //postcondition: intitializes unsingned int
    typedef int64_t item;
    //precondition: none
    //postcondition: push value (number)
    //in to the pointer
    void push(item entry);
    //precondition:none
    //postcondition: pushes value(character) 
    //out of pointer
    void push(char sun);
    //precondition: checks if it character or int
    //postcondition: stores characters into the pointer
    item pop(bool);
    //precondition: sets up the condition
    //postcondition: it it's true it pops number
    //if is false it pops character
    bool ready();
    //precondition: sets up the condition
    //postcondition: returns tue if 
    // there is operator, operand and amother 
    //operand next to each other.
private:
    //precondition: none
    //postcondition: declares the struct node
    struct node{
        int value;
        char optr;
        bool it_value;
        node *next;
    };
    node  *first;
    //precondition: none
    //postcondition: creates new poiter.
    void get_node();
};
