#include<iostream>
#include<stack>
using namespace std;
int main()
{

int n1,n2,n,num,num1,num2,carry,sum;
stack<int>a;
stack<int>b;
stack<int>c;

carry=0;
cout<<"Enter Number of bits of first number : ";
cin>>n1;
cout<<"Enter Number of bits of second number : ";
cin>>n2;
cout<<"Enter number bit by bit";
cout<<"\nEnter First number : ";
for(int i=0;i<n1;i++)
{
cin>>num1;
a.push(num1);
}
cout<<"Enter second number : ";
for(int i=0;i<n2;i++)
{
cin>>num2;
b.push(num2);
}
while(!a.empty() && !b.empty() )
{
num1=a.top();
num2=b.top();
a.pop();
b.pop();
if(num1+num2+carry==0)
{
sum=0;
carry=0;
c.push(sum);
}
else if(num1+num2+carry==1)
{
sum=1;
carry=0;
c.push(sum);
}
else if(num1+num2+carry==2)
{
sum=0;
carry=1;
c.push(sum);
}
else if(num1+num2+carry>2)
{
sum=1;
carry=1;
c.push(sum);
}
}
if(carry==1)
{
  c.push(carry);
}
cout<<"Addition of binary number is : ";
while(!c.empty())
{
num=c.top();
c.pop();
cout<<num;
}
return 0;
}