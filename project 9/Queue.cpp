#include <iostream>
#include <fstream>
#include "Queue.h"
//modification member of the class
void Queue :: enqueue(item entry)
{
    if(count<capacity)
    {
        rear=next_index(rear);
        data[rear]=entry;
        ++count;
    }
}
//modification member of the class
Queue::item  Queue::dequeue()
{
    item it;
    if(count>0)
    {
        it=data[front];
        front=next_index(front);
        --count;
    }
    return it;
}
//modification member of the class
ostream& operator<<(ostream & out_s, Queue g)
{
    int  it;
    int m=g.length();
    for(int i=0; i<m; i++)
    {
        it=g.dequeue();
        out_s<<it <<" ";
        g.enqueue(it);
    }
    return out_s;
}
