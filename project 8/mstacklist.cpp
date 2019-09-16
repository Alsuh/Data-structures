#include <iostream>
#include <fstream>
#include "Stacklist.h"
#include <cmath>
using namespace std;
//rhis where the main(clienf) starts
int main()
{	
	Stack l1;                                      
	int64_t word;
	ifstream infile;
	ofstream outfile;
	string input_file_name, output_file_name;
	cout<<" pleade Enter the name of the input file "<<endl;
	cin>>input_file_name;
	infile.open(input_file_name.c_str());
	if(!infile)
	{
		cout<<" couldn't reach the name of the output file"<<endl;
		return 0;
	}
    //
	char ch;
    //
	int64_t result;
	cout<<" the expressions is "<<" ";
    //
    while(infile.peek() != EOF )
    {
    	char ch;
        if(infile>>ch && ch !=' ' && ch != '\n')
        {
            if(isdigit(ch))
            {
                cout<<(int64_t)ch-'0'<<" ";
                l1.push((int64_t) ch-'0');
            }
            else
            {
                cout<< ch <<" ";
                l1.push(ch);
            }
            while(l1.ready())
            {
                int64_t oprnd2 = l1.pop(true);
                int64_t oprnd1 = l1.pop(true);
                char optr = l1.pop(false);
                //cout << "POPPED: " << oprnd2 << endl;
                //cout << "POPPED: " << oprnd1 << endl;
                //cout << "POPPED: " << optr << endl;

                if(optr== '+')
                {
                    result= oprnd1 + oprnd2;
                    l1.push(result);
                }
                else if(optr=='-')
                {
                    result= oprnd1 - oprnd2;
                    l1.push(result);
                }
                else if(optr=='*')
                {
                    result= oprnd1 * oprnd2;
                    l1.push(result);
                }
                else if(optr=='/')
                {
                    result= oprnd1 / oprnd2;
                    l1.push(result);
                }

            }

        }
    }
    cout<<" "<<endl;
    cout<<"Value is : "<< l1.pop(true)<<endl;
    infile.close();
    return 0;
}
