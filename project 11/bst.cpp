#include "bst1.h"
#include <cstring>
#include <iomanip>
//modfication of BST

BST:: ~BST()
{
	destroy(root);
}
void BST:: destroy(node* p)
{
	if(p!=NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p=NULL;
	}
}
void BST:: insert(item id, char name[], item quantity, int price)
{
	r_insert(root,id,name,quantity,price);
}
void BST:: r_insert(node* &t,int id, char name[], int quantity, double price)
{
	if(t==NULL)
	{
		t= new node;
		t->id1=id;
		strcpy(t->name1, name);
		t->quantity1=quantity;
		t->price1=price;
		t->left = NULL; 
        t->right = NULL;
	}
	else if(id<t->id1)
	{
		r_insert(t->left,id,name,quantity,price);
	}
	else
	{
		r_insert(t->right,id,name,quantity,price);
	}
}
void BST:: remove(item id)
{
	r_remove(root,id);
}
void BST:: r_remove(node *&t, item id)
{
	if(t->id1==id)
	{
		remove_node(t);
	}
	else if(t->id1>id)
	{
		r_remove(t->left,id);
	}
	else
	{
		r_remove(t->right,id);
	}
}
void BST::remove_node(node *&r)
{
	node*ptr;
	node*back;
	if(r->left==NULL && r->right==NULL)
	{
		delete r;
		r=NULL;
	}
	else if(r->left==NULL)
	{
		ptr=r;
		r=r->right;
		delete ptr;
	}
	else if(r->right==NULL)
	{
		ptr=r;
		r=r->left;
		delete ptr;
	}
	else
	{
		back=r;
		ptr=r->right;
		while(ptr->left!=NULL)
		{
			back=ptr;
			ptr=ptr->left;
		}
		r->id1 = ptr->id1;
		if(back==r)
			remove_node(back->right);
		else
			remove_node(back->left);
	}
}
void BST:: report(int id)
{
	node* r;
	r=root;
	while(id != r->id1)
	{
		if(id< r->id1)
			r=r->right;
		else
			r=r->left;
	}
		std::cout << "  " << std::left << std::setw(12) << "Name:"<<r->name1<<std::endl;
   		std::cout << "  " << std::left << std::setw(12) << "Quantity:"<<r->quantity1<<std::endl;
   		std::cout << "  " << std::left << std::setw(12) << "Price:"<<r->price1;
   	}
   	std::ostream &operator << (std::ostream& out_s, BST& t) 
{ 
    t.printinventory(out_s, t.root); 
    return out_s; 
} 
   	void BST::printinventory(std::ostream& out_s, node*r) 
{ 
    if (r != NULL) 
    { 
        printinventory(out_s, r->left); 
        out_s << std::right<< std::setw(5)<< r->id1<< std::setw(4) << "  ";               
		out_s << std::left<< std::setw(12)<< r->name1; 
        out_s << std::right<< std::setw(5)<< r->quantity1<<std::setw(3)<<"  "; 
        out_s << std::right << std::setw(8) << std::fixed;
        out_s << std::setprecision(2) << r->price1 << "\n"; 
        printinventory(out_s, r->right);
    } 
}
double BST::totalvalue() 
{ 
    return help_totalvalue(root);
}

double BST::help_totalvalue(node* r) 
{ 
    if (r != NULL)
    {
    	return ( (r->price1 * r->quantity1) + 
		help_totalvalue(r->left) + 
		help_totalvalue(r->right) );
	}    
	else 
        return 0;
}
