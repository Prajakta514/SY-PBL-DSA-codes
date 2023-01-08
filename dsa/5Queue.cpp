#include<iostream>
using namespace std;
class QueueNode
{ public:
  int data;
  QueueNode*next;
};
class QueueNew
{
QueueNode *rear,*front;
int size;
public:
int empty();
int Delete();
void insert(int element);
int GetFront();
QueueNew()
{
front=rear=NULL;
}
};  
int QueueNew::empty()
{
if(front==NULL)
return 1;
else
return 0;
}
void QueueNew::insert(int value)
{ QueueNode *Newnode;
Newnode=new QueueNode;
Newnode->data=value;
Newnode->next=NULL;
if(rear==NULL)
{
front =Newnode;
rear=Newnode;
}
else
{
  rear->next=Newnode;
  rear=Newnode;
 }
}
int QueueNew::Delete()
{
int temp;
QueueNode *curr=NULL;
if(!empty())
{
temp=front->data;
curr=front;
front=front->next;
delete curr;
return temp;
}
else
{
  cout<<"Queue is empty";
  return 0;
 }

}
int QueueNew::GetFront()
{  
if(!empty())
{
return (front->data);
}
else
return 0;
}
int main()
{ QueueNew obj;
/*Q.insert(10);
Q.insert(20);
cout<<endl<<Q.Delete();
cout<<endl<<Q.GetFront()<<endl;*/
int c=obj.empty();
int element,choice;
 
  do
  {
  cout<<"Menu : \n\t1.For Checking Empty \n\t2.Push Operation\n \t3.Pop operation\n\t4.Get Front\n\t5.Exit\n";
  cout<<"Enter Your Choice : ";
  cin>>choice;
  switch(choice)
  {
  case 1:
        if( c==1)
            cout<<"Queue is Empty"<<endl;
        else
            cout<<"Queue is Not Empty"<<endl;
        break;
  case 2:
            cout<<"Enter Element to Insert : ";
            cin>>element;
            obj.insert(element);
        break;
  case 3 :
            cout<<endl<<"Deleted element ="<<obj.Delete()<<endl;
        break;
  case 4 :
            cout<<endl<<"Front Element= "<<obj.GetFront()<<endl;
            break;
  case 5:
            break;
 
  }
  }while(choice!=5);
return 0;
}

