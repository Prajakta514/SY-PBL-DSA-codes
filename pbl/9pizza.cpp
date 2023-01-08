#include<iostream>
 #include<string.h> 
using namespace std; 
class details 
{ 
string name; 
int choice,p=0,b=0,n=0,both=0; 
public: 
void get_data() 
{ 
cout<<"\nEnter you name: ";
cin>>name; 
 
cout<<"\n1.Pizza\n2.Burger\n3.Both\n4.None"; 
cin>>choice; 
if(choice==1) 
p++; 
else if(choice==2) 
b++; 
else if(choice==3) 
both++; 
else 
n++; 
} 
void display() 
{ 
cout<<"\nTotal Number of customers who like either pizza or burger or both: "<<(p+b+both); 
cout<<"\nNumber of customers who like both pizza and burger: "<<both; cout<<"\nNumber of customers who like only pizza, not burger: "<<p; 
cout<<"\nNumber of customers who like only burger not pizza: "<<b; 
cout<<"\nNumber of customers who like neither pizza nor burger: "<<n<<endl; 
} 
}; 
int main() 
{ 
details ob; 
int ch,i=0; 
while(1) 
{ 
cout<<"\n1.new entry\n2.exit\n"; 
cout<<"Enter: "; 
cin>>ch; 
if(ch==2) 
break; 
ob.get_data(); 
} 
cout<<"\nDisplay: ";
ob.display(); 
return 0; 
} 
