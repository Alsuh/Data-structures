//
//  List2.h
//
//
//  Created by Suhayb Ali on 2/14/18.
//
#include <iostream>
#include <fstream>
using namespace std;
#ifndef List2_hpp
#define List2_hpp
class List{
public:
    typedef int item;
   // preconstion
    //post condition.
    List(){ first=NULL;}
    //preconstion
    //post condition. deletes used nodes.
    ~List();
    //preconstion
    //post condition. reconstrcuter
    int length() ;
    //preconstion:none
    //post condition. calls the re_length fucntion to do operations
    void insert(item entry);
    //preconstion
    //post condition.alls the re_insert fucntion to do operations
    void remove(item target);
    bool present(item target);
    void make_empty();
    //preconstion
    //post condition. sets back everything to nothing
    bool isempty()const {return first==NULL;};
    //preconstion
    //post condition. checks if the list is empty.
    item kth ( std::size_t k );
    friend std::ostream& operator << ( std::ostream& out_s,
                                      const List& l );
private:
    struct node{
        node* next;
        item data;
    };
    //preconstion
    //post condition.
    int R_length(node*p);
    //preconstion-no precondition.
    //post condition- find the length of the list
    void R_insert(node* &p, item entry);
    //preconstion
    //post condition. inserts a value to the list
    void R_remove(node* &p, item target);
    //preconstion
    //post condition.calls private function
    bool R_present(item target,node* &p);
    //preconstion; none
    //post condition. checks if value is present.
    void R_make_empty(node* &p);
    //preconstion
    //post condition. make the list empty.
    void destroy(node* &);


    node*first;
    node* get_node(const item value, node*Link);
};

#endif /* List2_hpp */
