#include "fraction.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int Oper1()         //funtion that reads the operation
{
    char result;
    cout<<" what operation would you like";
    cin>>result;
    return result;
}
int main()
{
	fraction A,B;          //declaring class objects
    char us;
	cout<< " Enter the first fraction  ";
    A.read(cin);cout<<endl;
    us=Oper1();
    cout<<endl;
    cout<<" Enter the second fraction  ";
    B.read(cin); cout<<endl;
    // cout<<us<<endl;
    if(us == '/')
    {
        A.division(B);
    }
    else
    {
        if(us=='*')
        {
        A.multi(B);
        }
        else
        {
            if(us=='+')
            {
                A.addition(B);
            }
            else
            {
                    if(us=='-')
                    {
                    A.subtruction(B);
                    }
                    else
                        {
                    cout<<" you are option are add,subtruction,multi, and divition"<<endl;
                        }
                    }
              }

    }

	cout<< " thank you for using my program. goodbye"<<endl;
	return 0;
}
