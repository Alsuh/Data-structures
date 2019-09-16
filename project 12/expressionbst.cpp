#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "expressionbst.h"
ExpTree:: ExpTree()
{
	root=NULL;
}
ExpTree:: ~ExpTree()
{
	destroy(root);
}
int ExpTree:: value()
{
	return R_value(root);
}
int ExpTree:: R_value(node * &r )
{
	int l_value;
	int r_value;
	if(r->left==NULL)
	{
		return r->oprnd;
	}
	else
	{
		l_value=R_value(r->left);
		r_value=R_value(r->right);
	}
	if(r->optr=='+')
		return l_value + r_value;
	else if(r->optr=='-')
		return l_value - r_value;
	else if(r->optr=='*')
		return l_value * r_value;
	else if(r->optr=='/')
		return l_value / r_value;
	return 0;
}
void ExpTree:: prefix(ostream & out_s)
{
	r_prefix(out_s, root);
	out_s << endl;
}
void ExpTree:: r_prefix(ostream& out_s, node* & m)
{
	if(m->left==NULL)
	{
		out_s<< m->oprnd <<" ";
	}
	else
	{
		out_s<< m->optr <<" ";

		r_prefix(out_s, m->left);
		r_prefix(out_s, m->right);
	}
}
void ExpTree:: postfix(ostream & out_s)
{
	r_postfix(out_s, root);
	out_s << endl;
}
void ExpTree:: r_postfix(ostream& out_s, node* & m)
{
	if(m->left==NULL)
	{
		out_s<< m->oprnd <<" ";
	}
	else
	{
		r_postfix(out_s, m->left);
		r_postfix(out_s, m->right);
		out_s<< m->optr <<" ";
	}
}
void ExpTree:: infix(ostream & out_s)
{
	r_infix(out_s, root);
	out_s << endl;
}
void ExpTree:: r_infix(ostream& out_s, node* & m)
{
	if(m->left==NULL)
	{
		out_s<< m->oprnd <<" ";
	}
	else
	{
		out_s << "( ";
		r_infix(out_s, m->left);
		out_s<< m->optr <<" ";
		r_infix(out_s, m->right);
		out_s << ") ";
	}
}
void ExpTree:: build(ifstream & out_s)
{
	destroy(root);
	root= r_build(out_s);
}
ExpTree:: node* ExpTree:: r_build(ifstream & in_s)
{
	char ch;
	node* temp;
	in_s>>ch;
	if(!(isdigit(ch)))
	{
		temp= new node;
		temp->oprnd= ch-'0';
		temp->right=NULL;
		temp->left=NULL;
	}
	else
	{
		temp= new node;
		temp->left= r_build(in_s);
		in_s>> temp->optr;
		temp->right= r_build(in_s);
		in_s>>ch;
	}
	return temp;
}
void ExpTree:: destroy(node* & m)
{
	while(m!= NULL)
	{
		destroy(m->left);
		destroy(m->right);
		delete m;
		m=NULL;
	}
}
