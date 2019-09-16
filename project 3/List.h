//
//  List.hpp
//  
//
//  Created by Suhayb Ali on 2/3/18.
//
#include <iostream>
#include <fstream>
using namespace std;

#ifndef List_hpp
#define List_hpp
class List{

public:     							        // functions go under this.
    typedef int item;
    friend std:: ostream& operator << (std:: ostream& out_s, const List l );
	List(){ first=NULL;}   						//constructer
	~List();							        //deconstructer
	int length();						        // finds the length
	void insert(const item& entry);
    void merge(const List& suhayb1, const List& suhayb2);
    bool present ( const item& target ) const;  //check if two value are the same.
    void prin();
    
private:
    struct node{
            item data;
             node *next;

                };
                node* first;
    node* get_node(const item& value, node* link);
};
#endif /* List_hpp */
