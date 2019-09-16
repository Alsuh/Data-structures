#include <iostream>
#include <fstream>
#include <string>
#ifndef BST_H 
#define BST_H 
class BST{
public:
	typedef int item;
	//condition: none
	//post condition: sets the whole tree to null
	BST()
	{
		root=NULL;
	}
	//precondtion: none
	//postcondition: return tree if the root is null
	~BST();
	bool is_empty()
	{
		return root==NULL;
	}
	//precondition:null
	//postcondition: inters new item into the the binary search
	void insert(item id, char name[], item quantity, int price);
	//precondition: none
	//postcondition: removesitem from binary searcg
	void remove(item id);
	//precondition: none
	//postcondition: reports specifc item
	void report(int id);
	//precondition: none
	//postcondition: calculates the tottalvalue of the inventoty
	double totalvalue();
	//precondition: none
	//postcondition: ptints the contents out
	void print();
	//precondition: none
	//postcondition: eases the process of printing out
	friend std:: ostream &operator<<(std::ostream & out_s, BST &t);
private:
	//data type
	struct node{
		int id1;
		char name1[10];
		int quantity1;
		double price1;
		node *left;
		node *right;
	};
	node *root;
	//precondition: none
	//postcondition: helps insert item 
	void r_insert(node *&t,int id, char name[], int quantity, double price);
	//precondition: none
	//postcondition: helps romve an item
	void r_remove(node *& t, int id);
	//precondition: none
	//postcondition: calcutes total value
	double t_value(node *&t,int id);
	//precondition: none
	//postcondition: destroys nodes in the tree
	void destroy(node*p);
	//precondition:non
	//postcondition: helps romve a node
	void remove_node(node *&s);
	//precondition: none
	//postcondition: helps total value
	double help_totalvalue(node* r);
	//precondition: none
	//postcondition: none
	void printinventory(std::ostream &out_s, node* p);
};
#endif