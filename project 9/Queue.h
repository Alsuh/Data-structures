#include <iostream>
#include <fstream>
using namespace std;
class  Queue{
public:
    typedef int item;
    //declaring size of erray
    static const int capacity=150;
    //precondition : none 
    //postcondition : sets first,rear, and count to nothing.
    Queue()
    {
        front= 0;
        rear= capacity-1;
        count=0;
    }
    //modifications
    //precondition : none 
    //postcondition : pushes into the queue
    void enqueue(item entry);
    //precondition : none 
    //postcondition : pushes out of the queue
    item dequeue();
    //constant member functions
    //precondition : none 
    //postcondition : return count
    int length(){ return count;}
    //precondition : none 
    //postcondition : returns true when count is equal to zero
    bool empty(){ return count==0;}
    //precondition : none 
    //postcondition : overloads and prints out the value
    friend ostream& operator <<(ostream &out_s, Queue q);
private:
    //precondition : none 
    //postcondition : just the declartionn
    int front;
    int rear;
    int count;
    int data[capacity];
    //private function;
    //precondition : none 
    //postcondition : set rear to right behind from
    int next_index(int i)
    {
        return (i+1)%capacity;
    }
};
