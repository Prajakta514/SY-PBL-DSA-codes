#include<iostream>
using namespace std;
class Shape
{
private:
int x,y;
public:
virtual void display()=0;
};

class triangle : public Shape
{
int base,height;
float area;
public:
void get_data()
{
cout<<"\nEnter Base length of triangle : ";
cin>>base;
cout<<"Enter height length of triangle : ";
cin>>height;
area=(base*height/2);
}
void display()
{

cout<<"Area of Triangle= "<<area;
cout<<endl;
}

};
class Rectangle :public Shape
{
int len,bre,area;
public:
void get_data()
{
cout<<"\nEnter length of Rectangle : ";
cin>>len;
cout<<"Enter breadth of Rectangle : ";
cin>>bre;
area=len*bre;
}
void display()
{

cout<<"Area of Rectangle = "<<area;
cout<<endl;  
}
};

int main()
{
triangle T;
Rectangle R;
int choice;
do
{
cout<<"Menu:\n\t1.Area of Rectangle\n\t2.Area of triangle \n\t3.Exit"<<endl;
cout<<"Enter Your choice : ";
cin>>choice;
switch(choice)
{
case 1:
R.get_data();
R.display();
break;
case 2:
T.get_data();
T.display();
  break;
 case 3:
  break;
}

}while(choice!=3);
return 0;
}
