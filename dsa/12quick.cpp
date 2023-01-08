#include<iostream>
#include<cstring>
using namespace std;
class emp
{
  public:
    string name;
    int salary;
};
void swap(int m,int n)
{
    int t;
    t=m;
    m=n;
    n=t;
}
int partition(emp*a,int lb,int ub)
{
    int pivot=a[lb].salary;
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(a[start].salary<=pivot)
            start++;
         while(a[end].salary>pivot)
            end--;  
            if(start<end)
            {
                swap(start,end);
            }
    }
    swap(lb,end);
    return end;
}
void Quicksort(emp*a,int lb,int ub)
{int loc;
    if(lb<ub)
    {loc=partition(a,lb,ub);
     Quicksort(a,lb,loc-1);
     Quicksort(a,loc+1,ub);
    }
}
int main()
{
    cout<<"Enter total number of employees :";
    int n;
    cin>>n;
    //int a[n];
    emp a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Name of employee no. "<<i+1<<" : ";
         cin>>a[i].name;
        cout<<"\nEnter salary of employee no. "<<i+1<<" : ";
        cin>>a[i].salary;
       
    }
    Quicksort(a,0,n-1);
    cout<<"Top 5 employees having maximum salary \n";
    cout<<"\tName\tSalary\n";
     for(int i=n-1;i>=(n-5);i--)
    {cout<<"\t"<<a[i].name<<"  \t"<<a[i].salary<<endl;}
    return 0;
}
