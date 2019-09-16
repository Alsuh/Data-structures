//
//  Stack.hpp
//  
//
//  Created by Suhayb Ali on 3/12/18.
#include <iostream>
#include <fstream>
using namespace std;
//the class starts here
class Stack{
    //public part of the class
public:
    typedef int item;
    //constructer
    Stack()
    {
        used=0;
    }
    //modification
    //precondition: none
    //postcondition: store value in the stack
    //this push function is used to store value into the stack
    void push(item entry);
    //precondition:none.
    //postcondition: pushes value out of the stack.
    //this function is used to write out values on the screen.
    int pop();
    //precondition: used will equal to true.
    //postcondition: used will equal to false
    bool empty(){return used==0; }
    //the private part of the class.
private:
    //declaring the array size.
    item data[128];
    //declaring a private veriable
    int used;
};
