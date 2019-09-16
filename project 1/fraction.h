#include <fstream>
using namespace std;
#include <iostream>
#include <cstring>
#ifndef Fra
#define Fra
class fraction
{
private:
    int denominator;   //declaring the denominator
    int numerator;     // declaring the numerator
public:
    //constructer
    fraction(int d=1, int n=1)          // declaring the constructer
    {
        denominator=d;
        numerator=n;
    }
    void print()                        // this functions prints the outputs on the screen
    {
        cout<<denominator<<"/"<<numerator;

    }
    void getdenominator(int d)    // setting up a denominator funtion
    {
        denominator=d;
    }
    void getnumerator(int n)     // this function is used to get the numeriatoe
    {
        numerator=n;
    }
    //operaters
    bool division(const fraction right)const;    // declaring the parameter for divition function
    bool multi(const fraction right)const;       // declaring the parameter for divition function
    bool read(istream&);                         // declaring the parameter for divition function
    bool subtruction(const fraction right)const; // declaring the parameter for divition function
    bool addition(const fraction right)const;    // declaring the parameter for divition function

};
#endif
