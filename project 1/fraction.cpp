#include <cassert>
#include <cstdlib>
#include "fraction.h"
bool fraction:: division(const fraction right)const // the division function
{
    int c,d;

        c=(numerator)*(right.denominator);
        d=(denominator)*(right.numerator);
        cout<<c<<"/"<<d<<endl;
        return 0;
}
bool fraction :: multi(const fraction right)const   // multiplicatio function 
{
    int c,d;
    c=(numerator)*(right.numerator);
    d=(denominator)*(right.denominator);
    cout<<c<<"/"<<d<<endl;
    return 0;
}
bool fraction:: addition(const fraction right)const  // addition function
{
    int c,d;
    c=(numerator*right.denominator)+(denominator*right.numerator);
    d=denominator*right.denominator;
    cout<<c<<"/"<<d<<endl;
    return 0;
}
bool fraction :: subtruction(const fraction right)const // subtraction function
{
    int c,d;
    c=(numerator*right.denominator)-(denominator*right.numerator);
    d=denominator*right.denominator;
    cout<<c<<"/"<<d<<endl;
    return 0;
}

bool fraction:: read(istream& infile)               // reading functione
{
    char Operator;
    if(infile>>numerator>>Operator>> denominator)
    {
        return true;
    }
    else 
        {
            return false;
        }

}

