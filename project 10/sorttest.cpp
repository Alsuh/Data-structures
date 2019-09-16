#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int count1;
int count2;
int count3;
//insertion sort function is implented here
//perecondition: array one is not sorted
////pstcondition: array one is funnly sorted.
int insertsort(int array[],int number)
{
     for(int i=0; i<=number; i++)
    {
         for(int j=0; j<i; j++)
        {
            while(array[j]<array[j-1])
            {
                int tm=array[j-1];
                array[j-1]=array[j];
                array[j]=tm;
                j--;
                count1++;
            }
        }
    }
    cout<<" "<<endl;
    return count1;
}
    //merge sort srats here.
//precondition: array 2 is filled with randon numbers and not sorted
//post condition: arrray 2 is fullly sorted.
int Merge(int A[],int p, int q,int r)     /*It merges two arrays */
{
int n1=q-p+1,i,j,k;       /*n1 is the size of L[]*/
int n2=r-q;               /*n2 is the sixe of R[]*/
int L[n1],R[n2];
for(i=0;i<n1;i++)
{
L[i]=A[p+i];
}
for(j=0;j<n2;j++)
{
R[j]=A[q+j+1];
}
i=0,j=0;
for(k=p;i<n1&&j<n2;k++)
{
    count2++;
if(L[i]<R[j])
{
A[k]=L[i++];
}
else
{
A[k]=R[j++];
}
}

while(i<n1)             /*If L[] has more elements than R[] then it will put all the reamining elements of L[] into A[]*/
{
A[k++]=L[i++];
}
while(j<n2)             /*If R[] has more elements than L[] then it will put all the reamining elements of R[] into A[]*/  
{
A[k++]=R[j++];
}
return count2;
}

void MergeSort(int A[],int p,int r)    /*It will will divide the array and sort them while merging them*/
{
int q;                                

if(p<r)
    {
q=(p+r)/2;                      /*q is the middle element to divide the array*/ 
MergeSort(A,p,q);
MergeSort(A,q+1,r);
Merge(A,p,q,r);
    }
}

//the quick sort start from here
//precondition:array 3 is not sorted
//postcondition: array is sorted.
void exchange(int a[],int first, int last)
{
    int temp= a[first];
    a[first]=a[last];
    a[last]=temp;
}
int partition(int a[],int low, int high, int pivet, int &i, int &j)
{
    int lasts1=low-1;
    int firstu=low;
    int firsts3=high + 1;
    while(firstu<firsts3)
    {
        count3++;
        if(a[firstu]<pivet)
        {
            lasts1++;
            exchange(a, lasts1, firstu);
            ++firstu;
        }
        else if(a[firstu]==pivet)
        {
            ++firstu;
        }
        else
        {
            --firsts3;
            exchange(a, firstu, firsts3);
        }
    }
    i=lasts1;
    j=firsts3;
    return count3;
}
void quick_sort(int a[],int low, int high)
{
    int pivet;
    int firsts3,lasts1;
    if(low<high)
    {
        pivet=a[low];
        partition(a,low,high,pivet, lasts1,firsts3);
        quick_sort(a,low,lasts1);
        quick_sort(a, firsts3, high);
    }
}

int main()
{
    int number;
    int count4=0;
    int count5=0;
    int count6=0;
    int array1[500];
    int array2[500];
    int array3[500];
    int seed;
    cout<<"Enter the number of values to generate and sort, between 1 and 500: "<<endl;
    cin>>number;
    cout<<"Enter an integer seed value:"<<endl;
    cin>>seed;
    srand(seed);
     cout<<"--------------------------------"<<endl;
     cout<<"firsr array is coming "<<endl;
    while(count4<number)
    {
    	array1[count4]= rand()%8192;
    	cout<<array1[count4]<<" ";
    	count4++;
    }
    cout<<" "<<endl;
    insertsort(array1,number);
    cout<<"insertion is sorting the first array"<<endl;
    for(int a=0; a<number; a++)
    {
        cout<<array1[a]<<" ";
    }
    cout<<" "<<endl;;
    cout<<"--------------------------------"<<endl;
    cout<<"second array is "<<endl;
    while(count5<number)
    {
        array2[count5]= rand()%8192;
        cout<<array2[count5]<<" ";
        count5++;
    }
    cout<<" "<<endl;
    MergeSort(array2,0,number-1);
    cout<<"merge sort is sorting the second array"<<endl;
    for(int b=0; b<number; b++)
    {
        cout<<array2[b]<<" ";
    }
    cout<<" "<<endl;
     cout<<"--------------------------------"<<endl;
     cout<<"third array is "<<endl;
    while(count6<number)
    {
        array3[count6]= rand()%8192;
        cout<<array3[count6]<<" ";
        count6++;
    }
    cout<<" "<<endl;
    quick_sort(array3,0,number-1);
    cout<<"quick sort is sorting the third array"<<endl;
    for(int c=0; c<number; c++)
    {
        cout<<array3[c]<<" ";
    }
    cout<<" "<<endl;
    cout<<"insertion sort count is "<<count1<<endl;
    cout<<"quick sort count is "<<count3<<endl;
    cout<<"merge sort count is "<<count2<<endl;
    return 0;
}
