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
#include "List2.h"
List :: ~List()
{
    node* temp;
    while(first != NULL)
    {
        temp=first;
        first=first->next;
        delete temp;
    }
}
void List :: print()
{
    node* suhayb;
    suhayb=first;
    while(suhayb!= NULL)
    {
        cout<< suhayb->data <<"";
        suhayb=suhayb->next;
    }
    cout<<""<<endl;
}
int List ::length() const
{
    item counter=0;
    node *p;
    p=first;
    while(p!= NULL)
    {
        counter++;
        p=p->next;
    }
    return counter;
}
void List :: insert(const item& inter)  //this user to add value into the list
{
        node *prev;
        if(first == NULL || inter < first->data )
            first= get_node(inter, first);
        else
        {
            prev = first;
            while((prev->next != NULL) && (prev->next->data < inter))
                prev = prev->next;
            prev->next = get_node(inter, prev->next);
            prev = prev->next;
        }
}
void List:: remove(const item& target)
{
    node *temp;
    node *prev;

    assert ( present(target) );

    prev = first;
    if ( prev->data == target )
    {
        first = first->next;
        delete prev;
    }
    else
    {
        while ( prev->next != NULL && prev->next->data < target )
            prev = prev->next;
        temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
}
List:: node* List:: get_node(const item& value, node* link) //private function that creates nodes
{
    node* temp;
    temp= new node;
    temp-> data =value;
    temp-> next = link;
    return temp;
}
bool List::present ( const item& target ) const //check if two value are the same.
{
    node *cursor;

    for ( cursor=first;
         cursor!=NULL && cursor->data!=target;
         cursor=cursor->next )
        ;   // The loop's body is empty.
    return ( cursor != NULL );
}
void List:: make_empty()
{
    node* temp;
    while(first!= NULL)
    {
        temp=first;
        first=first->next;
        delete temp;
    }
}
List::item List::kth ( size_t k ) const
{
    node *cursor;
    size_t count;

    assert ( 1 <= k && k <= length() );

    cursor = first;
    for (count=1; count<k; ++count)
        cursor = cursor->next;
    return cursor->data;
}
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



