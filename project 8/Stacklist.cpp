//
//  Stacklist.cpp
//  
//
//  Created by Suhayb Ali on 3/17/18.
//
#include <iostream>
#include "Stacklist.h"
using namespace std;
//modificatio of member function.
Stack:: Stack()
{
	first= NULL;
}
//modifaction of memberfunction,it pushes numbers
void Stack:: push(item entry)
{
	get_node();
	first->value=entry;
	first->it_value=true;
	//cout << "PUSHED: " << entry << endl;
}
//modifcation function 
void Stack:: push(char sun)
{
	get_node();
	first->optr=sun;
	first->it_value=false;
	//cout << "PUSHED: " << sun << endl;
}
// modifcation function
int64_t Stack:: pop(bool target)
{
	int64_t non;
	if(target)
	{
		non=first->value;
	}
	else
	{
		non=(int64_t) first->optr;
	}
	node *temp=new node;
	temp=first->next;
	delete first;
	first = temp;
	return non;

}
//checks if certain requirements are met 
//also part of modification function
bool Stack:: ready()
{
	if(first && first->it_value &&
		first->next && first->next->it_value &&
		first->next->next && !first->next->next->it_value)
	{
		return true;
	}
	return false;
}
//creates new node
//also part of modification.
void Stack:: get_node()
{
	node* temp;
	temp= new node;
	temp->next=first;
	first=temp;
}