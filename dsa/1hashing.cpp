#include<iostream>
#include<string>
using namespace std;
# define size 10

class Hash
{ private:
    struct Tel
    {
         string emp_name;
         string com_name;
         int Contact_no;
  }Tel[size];
 
  public:
         void insert();
         void display();
         long int Hash_fun( int);
         void Lcollision( int,string,string, int);
         void Qcollision( int,string,string, int);
         
   Hash(){
        for(int i=0;i<size;i++){
           Tel[i].Contact_no=0;
           Tel[i].com_name='_';
           Tel[i].emp_name='_';
       }
   }
};
long int Hash:: Hash_fun( int num){
    return (num% size);
}
void Hash::insert(){
    string Ename;
    string Cname;
     int No,Loc;
    int ch;
   
    cout<<"\nEnter employee name : ";
    cin>>Ename;
    cout<<"\nEnter Company name : ";
    cin>>Cname;
    cout<<"\nEnter Contact No : ";
    cin>>No;
    Loc= Hash_fun(No);
   
      if(Tel[Loc].Contact_no==0)
      {  
          Tel[Loc].emp_name =Ename;
          Tel[Loc].com_name =Cname;
          Tel[Loc].Contact_no =No;
          display();
         
      }
   
   
    else
    { cout<<"\nCollision occured "<<endl;
       
     cout<<"Enter Your Choice :1)Linear Probing 2)Quadratic probing : ";
     cin>>ch;
     cout<<endl;
     switch(ch)
     {
         case 1:
         Lcollision(Loc,Ename,Cname,No);
         cout<<endl;
         display();
         break;
         case 2:
         Qcollision(Loc,Ename,Cname,No);
         cout<<endl;
         display();
         break;
     }
 }
}
void Hash::display(){
    cout<<"Employee Name\t Company Name \tContact_no"<<endl;
   
    for(int j=0;j<size;j++){
    cout<<Tel[j].emp_name<<"\t\t"<<Tel[j].com_name<<"\t\t"<<Tel[j].Contact_no<<endl;
   }
}
void Hash::Lcollision(int l,string e,string c, int num){
    //int i,newi;
   /* if(l==9){
        l=0;
    }
    for(i=l;i!=(l-1);i++)
    {
       
       for(int j=1;j<=size;j++){
        i=(l+j)%size;
       
        if(Tel[i].Contact_no==0)
        {Tel[i].emp_name=e;
        Tel[i].com_name=c;
        Tel[i].Contact_no=num;
        break;
        }
       }
    }*/
    int k,new_loc;
for(k=0;k<size;k++)
{
new_loc=(l+k)%size;
if(Tel[new_loc].Contact_no==0)
        {
          Tel[new_loc].emp_name=e;
          Tel[new_loc].com_name=c;
          Tel[new_loc].Contact_no=num;
          break;
        }
    }
}
   

void Hash::Qcollision(int l,string e,string c, int num){
      int k,new_loc;
        for(k=0;k<size;k++)
        {
            new_loc=(l+(k*k))%size;
        if(Tel[new_loc].Contact_no==0)
        {
             Tel[new_loc].emp_name=e;
             Tel[new_loc].com_name=c;
             Tel[new_loc].Contact_no=num;
          break;
        }
    }
    }
   
int main(){
   
    int element,ch;
    cout<<"Enter Number of Elements : ";
    cin>>element;
   

    Hash H;
    for(int i=0;i<element;i++){
    H.insert();
       
    }
   
    H.display();
   

return 0;
}