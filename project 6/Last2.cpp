//
//  List2.cpp
//
//
//  Created by Suhayb Ali on 2/14/18.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;
#include "Last.h"
// the copys constructer public face.
List :: ~List()
{
    destroy(first);
}
//the copy constructers implementation.
void List:: destroy(node* &p)
{
    if(p->next==NULL)
    {
        delete p;
    }
    else
    {
        destroy(p->next);
        delete p;
    }
    p = NULL;
    return;
}
// insert function public face.
void List:: insert(item entry)
{
    R_insert(first,entry);
}
//insert functions ptivate face/inplementation
void List:: R_insert(node* &p, item entry)
{
    if(p==NULL || p->data > entry)
    {
        p=get_node(entry,p);
    }
    else
    {
        R_insert(p->next,entry);
    }
}
//get node function.
List:: node* List:: get_node(const item value, node* link)
{
    node* temp;
    temp= new node;
    temp-> data =value;
    temp-> next = link;
    return temp;
}
//remove function public phase.
void List:: remove(item target)
{
    R_remove(first,target);
}
//remove function private version/implementation.
void List:: R_remove(node* &p, item target)
{
    node* temp;
    if(p->data==target)
    {
        temp=p;
        p=p->next;
        delete temp;
    }
    else
    {
        R_remove(p->next,target);
    }
}
//the kth element functio.
List::item List::kth ( size_t k )
{
    node *cursor;
    size_t count;

    assert ( 1 <= k && k <= length() );

    cursor = first;
    for (count=1; count<k; ++count)
        cursor = cursor->next;
    return cursor->data;
}
//length public version that calls the private version.
int List:: length()
{
    return R_length(first);
}
//the length of private version that do the implementation.
int List:: R_length(node* p)
{
    if(p==NULL)
        return 0;
    return 1 + R_length(p->next);
}
//make empty publick version that call the private version.
void List:: make_empty()
{
    R_make_empty(first);
}
//the make empty private version that do the implementation.
void List:: R_make_empty(node* &p)
{
    if(p->next==NULL)
    {
        delete p;
    }
    else
    {
        destroy(p->next);
        delete p;
    }
    p = NULL;
    return;
}
// prsents public version.
bool List:: present(item target)
{
    return R_present(target,first);
}
//present private version.
bool List:: R_present(item target, node* &p)
{
    if(p->data==target)
    {
        return true;
    }
    else if(p!=NULL && p->data > target)
    {
        return R_present(target,p->next);
    }
    else
    {
        return false;
    }
}
//overload 
ostream& operator << ( ostream& out_s, const List& l )
{
    List::node *cursor;

    out_s << '(';
    for ( cursor=l.first;
         cursor != NULL && cursor->next != NULL;
         cursor=cursor->next )
        out_s << cursor->data << ", ";
    if ( cursor != NULL )
        out_s << cursor->data;
    out_s << ')';

    return out_s;
}

