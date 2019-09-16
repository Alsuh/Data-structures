//
//  Stack.cpp
//  
//
//  Created by Suhayb Ali on 3/12/18.
//
#include <iostream>
#include <cmath>
using namespace std;
#include "Stack.h"
//modifcation from the header.
// main purpose is pushout values from the stack.
int Stack :: pop()
{
    return data[--used];
}
//modifications from the header.
//main purpose is to pushin values into the stack.
void Stack :: push(int entry)
{
    data[used++]=entry;
}
