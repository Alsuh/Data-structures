#include "Queue.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
//function that fincs the shortest queue.
int shortest_q(Queue a[],int tran_time[], int howmanyques)
{
	int shortest=0;
	for(int i=0; i<howmanyques; i++)
	{
        if (tran_time[i]==0)
        {
            return i;
        }
		if(a[i].length() < a[shortest].length())
		{
			shortest=i;
        }
    }
    return shortest;
}
int main()
{
	int duration, arv_prob,maxtrans_time,howmanyques=1;
	int time=0;
	int count=0;
	int entry_time;
	int wait_sum=0;
	int wait_time;
	int store;
	int seed;
	int longest=0;
	cout<<" what is your logest possible time for transection"<<endl;
	cin>>maxtrans_time;
	cout<<" what is the duration time "<<endl;
	cin>>duration;
	cout<<" how many queues do you want to open "<<endl;
	cin>>howmanyques;
	cout<<"the probability that a customer will arrive "<<endl;
	cin>>arv_prob;
	cout<<"seed"<<endl;
	cin>>seed;
	int tran_time[howmanyques];
	for (int i = 0; i < howmanyques; i++) {
		tran_time[i] = 0;
	}
	Queue Line[howmanyques];


	for(time=0; time<duration; time++)
	{
		if(rand()%100<arv_prob)
		{
			Line[shortest_q(Line,tran_time,howmanyques)].enqueue(time);

		}

		for (int i=0; i<howmanyques; i++)
		{
			if(tran_time[i]==0)
			{
				if(!Line[i].empty())
				{
					entry_time=Line[i].dequeue();
					int wait_time = time-entry_time;
					if (wait_time > longest) {
						longest = wait_time;
					}
					wait_sum += wait_time;
					++count;
					tran_time[i]=(rand()%maxtrans_time)+1;
				}
			 else if (tran_time[i] > 0)
			{
				tran_time[i]--;
			}
            }
		}

		cout<<"Tick: " << time+1<<endl;
		for(int i=0; i<howmanyques; i++)
		{
			cout<< "\t" << tran_time[i] << " " << Line[i]<<endl;
		}
		cout << endl;
	}
	int average=wait_sum/count;
	cout<<endl;
	cout<<count<<"customers waited an everage of "<<average<<" ticks"<<endl;
	cout<<"the longest wait that a customer waited was "<<longest<<endl;

	return 0;

}
