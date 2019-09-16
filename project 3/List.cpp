//
//  List.cpp
//  
//
//  Created by Suhayb Ali on 2/3/18.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;
#include "List.h"

List :: ~List()                         //constructer
{
    node* temp;
    while(first!= NULL)
    {
        temp=first;
        first=first->next;
        delete temp;
    }
}
void List :: prin()                 //print function to output the result.
{
    node* suhayb;
    suhayb=first;
    while(suhayb!= NULL)
    {
        cout<< suhayb->data <<"  ";
        suhayb=suhayb->next;
    }
    cout<<""<<endl;
}
int List :: length()            //lenght is used to measure how long is the file.
{
    item count = 0;
    node *p;
    p=first;
    while(p != NULL)
    {
        count++;
        p=p->next;
    }
    return count;
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
List:: node* List:: get_node(const item& value, node* link) //private function that creates nodes
{
    node* temp; 
    temp= new node;
    temp-> data =value;
    temp-> next = link;
    return temp;
}
/*ostream& operator << ( ostream& out_s, const List  l )
{
    List:: node *cursor;
    out_s << '(';
    for ( cursor=l.first;
         cursor != NULL && cursor->next != NULL;
         cursor=cursor->next )
        out_s << cursor->data << ", ";
    if ( cursor != NULL )
        out_s << cursor->data;
    out_s << ')';

    return out_s;
} */
bool List::present ( const item& target ) const //check if two value are the same.
{
    node *cursor;

    for ( cursor=first;
         cursor!=NULL && cursor->data!=target;
         cursor=cursor->next )
        ;   // The loop's body is empty.
    return ( cursor != NULL );
}
void List::merge(const List& list1,const List& list2) // combines the two list into one.
{
    node*last;
    node *p1;
    node *p2;
    p1 = list1.first;
    p2 = list2.first;
    if(p1!=NULL && p2 != NULL)
    {
        if(p1->data < p2->data)
        {
            first=get_node(p1->data,NULL);
            p1=p1->next;
        }
        else if(p2->data < p1->data)
        {
            first = get_node(p2->data,NULL);
            p2=p2->next;
        }
        else
        {
            first = get_node(p1->data,NULL);
            p1=p1->next;
            p2=p2->next;
        }
        last=first;
    }
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data)
        {
            last->next = get_node(p1->data,NULL);
            p1=p1->next;
        }
        else if(p2->data < p1->data)
        {
            last->next = get_node(p2->data,NULL);
            p2=p2->next;
        }
        else
        {
            last->next = get_node(p2->data, NULL);
            p1=p1->next;
            p2=p2->next;
        }
        last= last->next;
    }
    while(p1!= NULL)
    {
        last->next=get_node(p1->data,NULL);
        p1=p1->next;
        last=last->next;
    }
    while(p2!=NULL)
    {
        last->next=get_node(p2->data,NULL);
        p2=p2->next;
        last=last->next;
    }
}

