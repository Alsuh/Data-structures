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
    List(){ first=NULL;}
    ~List();
    int length()const ;
    void insert(const item& entry);
    void remove(const item& target);
    void print();
    bool present(const item& target) const;
    void make_empty();
    bool isempty()const {return first==NULL;};
    item kth ( std::size_t k ) const;
    friend std::ostream& operator << ( std::ostream& out_s,
                                      const List& l );
private:
    struct node{
        node* next;
        item data;
    };
    node*first;
    node* get_node(const item& value, node*Link);
};

#endif /* List2_hpp */
