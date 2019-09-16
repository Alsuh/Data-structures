#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "List2.h"

using namespace std;

//fucntion prototype
void showmenu();
//This fucntion provides the better option or framework for user to do the operation.
//it indicates and makes clear which character to enter to carry out the desire
//operation when this fucntion is called.

int main()
{
    List list1;            //object of the class that can invoke the class's fucntion
    int v;                 //integer value
    char choice;        //character type that keeps track which operation to carry out

    showmenu();            //this fucntion  is initially called to give user various options

    while(choice != 'q') //user can do as many operations as they want until they q is pressed//exit option
    {
        cout<<" -->";
        cin>>choice;    //enters the character
        switch(choice)   //loop begins
        {
            case 'm': list1.make_empty();         //makes the invoking list empty
                break;

            case 'i': cin>>v;                    //enters any item in order to store in the list
                list1.insert(v);            //entered value is inserted in the invoking list
                break;                    //after inserting, break out of this loop

            case 'r': cin>>v;                    //enters the legit value from the list to remove from it
                list1.remove(v);            //removes the very value from the list
                break;                    //after removing, break out of loop

            case 'e': if(list1.isempty())//checks if the list is empty
                cout<<" The list is empty.\n";
            else
                cout<<" The list is not empty.\n";
                break;

            case 'l': if(list1.length() < 1)
                cout<<" The length of the given list is zero.\n";
            else
                cout<<" The length of the given list is: "<<list1.length()<<endl;//returns the length
                break;               //breaks out of loop

            case 'p': cin>>v;                    //enters the value to ckeck if its present
                if(list1.present(v))  //checks
                    cout<<" The value "<<v<<" is present in the list.\n";
                else
                    cout<<" The value "<<v<<" is NOT present in the list.\n";
                break;                    //breaks out of loop

            case 'k': cin>>v;                    //enters the position value to retrive the data of that position
                if((list1.isempty()) || (v > list1.length()))
                    cout<<" Not the valid selection.\n";
                else
                    cout<<" The "<<v<<"th element of the list is: "<<list1.kth(v)<<endl;
                break;                    //breaks out of loop

            case 'w': cout<<list1<<endl;        //writes out the items present in the invoking list
                break;                    //breaks out of loop

            case 's': showmenu();                 //this fucntion is again called within the loop
                break;                    //breaks out after calling

            default : break;                //default
        }
    }
}

//gives the framework for the program
void showmenu()
{
    cout<<" This program responds to the commands the user enters to manipulate\n";
    cout<<" an ordered list of integers which is initially empty. In the following \n";
    cout<<" commands, k1 is the position in the list and v is an integer.\n";
    cout<<endl;
    cout<<"    m  ----------Re-initialize the list to be empty.\n";
    cout<<"    i  v  -------Insert the value v into the list.\n";
    cout<<"    r  v  -------Remove the value v from the list.\n";
    cout<<"    e  ----------Is the list Empty?\n";
    cout<<"    l  ----------Report the length of the list.\n";
    cout<<"    p  v  -------Is the value v present in the list.\n";
    cout<<"    k  k1  ------Report the kth value in the list.\n";
    cout<<"    w  ----------Write out the list.\n";
    cout<<"    s  ----------See this menu.\n";
    cout<<"    q  ----------Quit\n";
    cout<<endl<<endl;
}
