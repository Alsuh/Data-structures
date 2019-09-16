#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "bst1.h"
//#include "bst.cpp"

using namespace std;

const int MAX=12;
void showMenu();
void readInputFilename(ifstream& infile, BST &t);
void insertItem(BST &t);
void reportItemInfo(BST &t,int number);
void print(BST &t);

int main()
{
    BST t;
    ifstream infile;
    int number;
    char choice;
    showMenu();
    while (choice != 'q')
    {
        cout << "--> ";
        cin >> choice;
        switch (choice)
        {
            case 'f': readInputFilename(infile, t); //Reads the items from the file
                break;

            case 'i': insertItem(t); // Insert an item into the inventory
                break;

            case 'r': cout<<" Item number to remove: ";
                cin >> number;
                t.remove(number); // remove an item from the inventory
                break;

            case 'e': if(t.is_empty()==true)
                cout<<" The inventory is empty. \n";
            else
                cout<<" The inventory is not empty. \n";
                break;

            case 'a': cout<<" Item number to report: ";
                cin >> number;
                reportItemInfo(t, number); // Reports an item's information
                cout << "\n";
                break;

            case 'v': cout << " The inventory's total value is ";
                cout << t.totalvalue() << "\n"; // Reports the total value of the inventory
                break;

            case 'p': print(t); // Prints the inventory to the terminal
                break;

            case 'h': showMenu(); // Displays the menu
                break;

            case 'q': break; // Exits program

            default:  cout << "Invalid command.  Type \"h\" to see the menu.\n";
                break;
        }//switch
    }//while
}

void showMenu()
{
    cout<<"This program responds to the following commands to \n";
    cout<<"manipulate an BST, which is initially empty.\n";
    cout<<"The commands prompt for additional information, if necessary.\n";
    cout<<endl;
    cout<< "    f  -- Read an BST from a file.\n";
    cout<< "    i  -- insert an item into the BST.\n";
    cout<< "    r  -- remove an item from the BST.\n";
    cout<< "    e  -- Report if the inventory is empty.\n";
    cout<< "    a  -- Report item's information.\n";
    cout<< "    v  -- Report the inventory's total value.\n";
    cout<< "    p  -- Print the inventory to the terminal.\n";
    cout<< "    h  -- See this menu.\n";
    cout<< "    q  -- Quit the program.\n";
}

// Adds inventory information from a file to the BST
void readInputFilename(ifstream& infile, BST &t)
{
    const int NAMESIZE = 20;
    char input_filename[NAMESIZE],name[MAX];
    int number, quantity;
    double price;
    cout << "Enter inventory file name: ";
    cin >> input_filename;
    infile.open(input_filename);
    if(!infile)
    {
        cout<<"cannot open the name of the input file.\n";
        infile.close();
        infile.clear();
        return ;
    }
    while (!infile.eof())
    {

        infile >> number;
        infile >> name;
        infile >> quantity;
        infile >> price;
        t.insert(number, name, quantity, price);
    }
    infile.close();
    infile.clear();
}

// Adds a new BST item or adds to an existing item
void insertItem(BST &t)
{
    int number;
    char name[MAX];
    int quantity;
    double price;
    cout << "Enter the description of an item:\n";
    cout << "  Number:   ";
    cin >> number;
    cout << "  Name:     ";
    cin >> name;
    cout << "  Quantity: ";
    cin >> quantity;
    cout << "  Price:    ";
    cin >> price;
    t.insert(number, name, quantity, price);
}

void reportItemInfo(BST &t, int number)
{
    t.report(number);
}

// Prints the entire inventory to the terminal
void print(BST &t)
{
    cout<< left << setw(9) << "Number";
    cout<< left << setw(12) << "Name";
    cout<< left << setw(8) << "Quantity";
    cout<< right << setw(8) << "Price";
    cout<< "\n-------------------------------------\n";
    cout<< t;
    cout<< "-------------------------------------\n";
}

