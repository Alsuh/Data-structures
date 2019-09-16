#include <iostream>
#include <cmath>
#include "Stack.h"
using namespace std;
// function used to fin the numbers.
//as well as push, pop values into the stack.
//precondtion:none
//postcondition: found all value and store them.
void primeFactor(int n)
{
    Stack s1;        //intializing an object
    while(n%2==0)
    {
        s1.push(2); //calling the push function store values
        n=n/2;
    }
    for(int i=3; i<=sqrt(n); i=i+2)
    {
        while(n%i==0)
        {
            s1.push(i); //second call also to store.
            n=n/i;
        }
    }
    //cout<<n<<endl;
    s1.push(n);

    cout<<" the prime factors are ";
    while(s1.empty()==false)
    {
        cout<<s1.pop()<<" ";//calling pop function to write out the value
    }
    cout<<endl;
}
int main()
{
    int number;             //intializing the int data type
    cout<<" what number do you want to find it's prime factors(0 to stop "<<endl;
    cin>>number;
    while(number!=0)
    {
        primeFactor(number);
        cin>>number;
    }
    return 0;
}
