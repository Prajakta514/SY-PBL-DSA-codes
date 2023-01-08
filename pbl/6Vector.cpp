/*Write a class template to represent a generic vector. Include member functions to perform the following tasks:
a To create the vector.
b To modify the value of a given element.
c To multiply the vector by a scalar value.
d To display the vector in the form (10, 20, 30)*/
#include<iostream>
using namespace std;
int size=0;
template <class T>
class vector
{
//int size=0;
T v[10];
   public:
    void create();
    void modify();
    void display();
    void mult();
};
template <class T>
void vector<T>::create()
{
T value;
char ans;
int n,j=0;
cout<<"Enter size of vector";
cin>>size;
//T v[size];

for(int i=0;i<size;i++)
{
cout<<"Enter Index : ";
cin>>j;
cout<<"Enter Value : ";
cin>>value;
v[j]=value;
//size++;
}

}
template <class T>
void vector<T>::modify()
{
int i;
T value;
cout<<"\nEnter Index to Modify : ";
cin>>i;
cout<<"Enter Value : ";
cin>>value;
v[i]=value;
display();

}
template <class T>
void vector<T>::display()
{
cout<<"Elements are:"<<endl;
for(int i=0;i<size;i++)
{
cout<<v[i]<<" ";
}
}

template <class T>
void vector<T>::mult()
{
int a;
    cout<<"\nEnter scalar value for multiplication";
    cin>>a;
    for(int i=0;i<size;i++)
    {
    v[i]=v[i]*a;
    }
display();

   
}


int main()
{
int ch;
    vector<int>obj;
do
    {
        cout<<"\nMENU\n1.Create\n2.Display\n3.Multiply\n4.Modify\n5.Exit\n";
       
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                obj.create();
                break;
               
            case 2:
                obj.display();
                break;
               
            case 3:
                obj.mult();
                break;
               
            case 4:
                obj.modify();
                break;
               
            case 5:
                cout<<"\nExit\n";
                break;
               
           
        }
    }while(ch!=5);
    return 0;
}
