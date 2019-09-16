#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "List.h"
using namespace std;
int main()                                  //main function starts here.
{
    List data1,data2, data3;
    int num;

    ifstream infile;
    int size=20;
    string input_file_name;

    cout<< " Please enter the name of the input file"<<endl;
    cin>> input_file_name;
    infile.open(input_file_name.c_str());
    if(!infile)
    {
        cout<<" couldn't open the file input file"<<endl;
        return 0;
    }
    while(infile>>num)              //while loop is used to read value from the file to the list.
    {
        data1.insert(num);
    }

    infile.close();
    cout<< " Enter the name of the name of the second file"<<endl;
    cin>>input_file_name;
    infile.open(input_file_name.c_str());
    if(!infile)
    {
        cout<<" couldn't open the file"<<endl;
        return 0;
    }
    while(infile>>num)
    {
        data2.insert(num);
    }
    infile.close();
    cout<<"-----------------------------------"<<endl;
    cout<<"the first file has the following value "<<endl;
    data1.prin();
    cout<<"length of the file is "<<data1.length()<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"the second file has the following value "<<endl;
    data2.prin();
    cout<<"length of the file is "<<data2.length()<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<" the merged List of both of them is "<<endl;
    data3.merge(data1,data2);
    data3.prin();
    cout<<"-----------------------------------"<<endl;
    cout<< " Good bye" <<endl;

    return 0;
}
