
//
//  expressionbst.hpp
//  
//
//  Created by Suhayb Ali on 4/22/18.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#ifndef expressionbst_h
#define expressionbst_h
using namespace std;
class ExpTree {
public:
	//prefix: none
	//postfix: intitialazes everything to null
	ExpTree();
	//prefix:none
	//postfix: empty out the the tree
	~ExpTree();
	//prefix: makes the tree is empty
	//postfix: files the tree with new value from the file
	void build(ifstream & );
	//prefix: none
	//postfix: prints the value in prefix order
	void prefix(ostream & );
	//prefix: none
	//postfix: prints the value in post order value
	void postfix(ostream& );
	//prefix: none
	//postfix: prints all value in infix order
	void infix(ostream & );
	//prefix: none
	//postfix: do the operation and print out the values
	int value();
	//prefix: none
	//postfix: returns true if the tree is empty
	bool is_empty();
private:
	//prefix: none
	//postfix: declaration of the node
	struct node {
		node* left;
		node* right;
		int oprnd;
		char optr;

			};
	node* root;
	//prefix: none
	//postfix: the private part of build function
	node* r_build(ifstream & );
	//prefix: none
	//postfix: private face of infix
	void r_prefix(ostream &, node * & );
	//prefix:none
	//postfix: private face of post fix
	void r_postfix(ostream & ,node * &  );
	//prefix: none
	//postfix: private face of infix 
	void r_infix(ostream &, node * & );
	//prefix: none
	//postfix: private part of value function
	int R_value(node * & );
	//prefix: none
	//postfix: deletes all the values in the tree.
	void destroy(node* &);

};


#include <stdio.h>

#endif /* expressionbst_hpp */
