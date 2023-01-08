#include<iostream>
using namespace std;
class Dnode
{ public:
int data;
Dnode *prev,*next;
Dnode()
{
prev=next=NULL;
}
};
class Dlist
{
private:
Dnode *head;
public:
void create();
void display();
void append(Dnode*newnode);
Dnode *getnode();
void Del(int);
void Insert_at_pos(Dnode* ,int);
void search();
Dlist()
{
head=NULL;
}
};
void Dlist::create()
{
Dnode*newnode;

char choice;
while(1)
{cout<<"Do you want to continue ?(Y/N)";
cin>>choice;
if(choice=='N')
break;
newnode=getnode();
append(newnode);}
}
Dnode *Dlist::getnode()
{
Dnode*Newnode;
Newnode=new Dnode;
cout<<"Enter data";
cin>>Newnode->data;
Newnode->next=NULL;
Newnode->prev=NULL;
return (Newnode);
}
void Dlist::append(Dnode*Newnode)
{
Dnode*temp=head;
if(head==NULL)
{head=Newnode;
temp=Newnode;}
else
{while(temp->next!=NULL)
{
temp=temp->next;
}
Newnode->prev=temp;

temp->next=Newnode;
temp=Newnode;
}
}
void Dlist::display()
{ Dnode*temp;
temp=head;
if(temp==NULL)
{
cout<<"List is Empty";
}
else
{
while(temp!=NULL)
{cout<<temp->data<<" ->";
temp=temp->next;
}
cout<<"NULL";
}
}
void Dlist::Insert_at_pos(Dnode *Newnode,int pos)
{Newnode=getnode();
Dnode*temp=head;
int count =1;
if(head==NULL)
head=Newnode;
else if(pos==1)
{
Newnode->next=head;
head->prev=Newnode;
head=Newnode;

}
else
{
while(count!=pos)
{ temp=temp->next;
if(temp!=NULL)
count++;
else
break;
}
if(count==pos)
{
(temp->prev)->next=Newnode;
Newnode->prev=temp->prev;
Newnode->next=temp;
temp->prev=Newnode;
}
else
{ cout<<"Position Not Found";
}
}
}
void Dlist::Del(int pos)
{Dnode*temp=head;
Dnode*curr;
int count=1,flag=1;
if(pos==1)
{ head=head->next;
delete temp;
}
else

{while(count!=pos)
{
temp=temp->next;
if(temp==NULL)
{
flag=0;
break;
}
count++;
}
if(temp->next==NULL && flag ==1)
{ curr=temp;
temp->prev->next=NULL;
delete curr;
}
else if(flag==1)
{ (curr->prev)->next=curr->next;
(curr->next)->prev=curr->prev;
delete curr;
}
else
{cout<<"Position Not Found";
}
}
}
void Dlist::search()
{ int value;
cout<<"Enter Element ";
cin>>value;
Dnode*temp=head;
int flag=0;

while(temp!= NULL)
{ if(temp->data==value)
{cout<<"Element Found "<<endl;
flag=1;
break;
}
temp=temp->next;
}
if(flag==0)
{
cout<<"Element Not Found"<<endl;
}
}
int main()
{Dnode*Newnode;
Dlist obj;
int choice,position;
do
{
cout<<"\nMenu: "<<endl;
cout<<"\t1.Create 2.Display 3.Insert At specific position 4.Delete Element 5.Search 6.Exit\n";
cout<<"Enter your choice : ";
cin>>choice;
switch(choice)
{ case 1:
obj.create();
break;
case 2:
obj.display();
break;
case 3:

cout<<"Enter the Position to Enter Element : ";
cin>>position;
obj.Insert_at_pos(Newnode ,position);
cout<<"Display After Insertion : ";
obj.display();
break;
case 4:
cout<<"Enter Position to delete the the Element : ";
cin>>position;
obj.Del(position);
cout<<"Display After deletion : ";
obj.display();
break;
case 5:
obj.search();
break;
case 6:
break;
}
}while(choice!=6) ;
return 0;
}