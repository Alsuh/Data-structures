#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include "expressionbst.h"
using namespace std;
int main()
{
	ifstream infile;
	string input_file_name;
	cout<<"Enter the name of input infile" <<endl;
	cin>>input_file_name;
	infile.open(input_file_name);
	if(!infile)
	{
		cout<<" couldn't reach the name of the input file"<<endl;
		return 0;
	}
	while(!infile.eof())
	{
		ExpTree* tree= new ExpTree;
		//tree->build(infile);
		cout<<"preorder ";tree->prefix(cout);
		cout<<"postorder ";tree->postfix(cout);
		cout<<"inorder ";tree->infix(cout);
		cout<< left<< setw(15)<< "value" << tree->value()<<endl <<endl;
		delete tree;
	}
	return 0;
}