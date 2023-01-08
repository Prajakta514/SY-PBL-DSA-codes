#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class student
{
   int Roll;
   char name[20];
   char clas[10];
   char div[20];
   char Blood_grp[5];
   char DOB[10];
   long int contact;
   char addr[20];
   public:
   void get_data();
   inline void display();
  static int count;
   void static countt()
   {
    count++;
    }
    student(){
   
    }
    ~student(){
   }
   

};
 int student::count=0;
void student::get_data()
{
    char ans;
    do{
cout<<"\nEnter Name of student : ";
cin>>name;
cout<<"\nEnter Roll No of student : ";
cin>>Roll;
cout<<"\nEnter Class of student : ";
cin>>clas;
cout<<"\nEnter Div of student : ";
cin>>div;
cout<<"\nEnter Blood Group of student : ";
cin>>Blood_grp;
cout<<"\nEnter DOB of student : ";
cin>>DOB;
cout<<"\nEnter Address of student : ";
cin>>addr;
cout<<"\nEnter Contact No. of student : ";
cin>>contact;
cout<<endl;
countt();
cout<<"do you want to add more?(y/n)";
cin>>ans;
}while(ans!='n');
}

void student:: display()
{
cout<<name<<"\t"<<Roll<<"\t"<<clas<<"\t"<<div<<"\t"<<Blood_grp<<"\t"<<DOB<<"\t"<<addr<<"\t"<<contact<<endl;
}

int main()
{ int n,i;

  
  cout<<"Enter Details of Students"<<endl;
student s;
 
   s.get_data();
  
   
   cout<<"Student Data is display below : "<<endl;
   cout<<"--------------------------------------------------------------------------------"<<endl;
   cout<<"Name\t"<<"Roll No\t"<<"Class  "<<"Div "<<"Blood_grp "<<" DOB  "<<"  Address "<<"Contact No "<<endl;
   for(int i=0;i<s.count;i++)
  {
   s.display();
   }
    cout<<"---------------------------------------------------------------------------"<<endl;
   cout<<"Count = "<<s.count<<endl;
 
  return 0;
  }
