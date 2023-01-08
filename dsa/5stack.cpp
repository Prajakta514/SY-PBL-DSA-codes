#include<iostream>

using namespace std;

class stack_node

{ public:
 int data;
               stack_node*next;
};
class stack_new
{
stack_node *top;
int size;
public:
int isempty();
int pop();
void push(int element);
int GetTop();
stack_new()
{
    top=NULL;
    size=0;
}

}; 

int stack_new::isempty()
{
if(top==NULL)
    return 1;
else
    return 0;
}

int stack_new::GetTop()
{
if(!isempty())
 return (top->data);
else
    return 0;
}

void stack_new::push(int value)
 {
  stack_node *Newnode;
  Newnode=new stack_node;
               Newnode->data=value;
  Newnode->next=top;
  top=Newnode;
 }
 int stack_new::pop()
 {
  stack_node *temp=top;
  int value;
   value=top->data;
    if(isempty())
         return 0;
  else
  { top=top->next;
        delete temp;
        return value;
  }
 }

 int main()
 { int choice,element;
  stack_new obj;
  int c=obj.isempty();
   do
 {
  cout<<"Menu : \n\t1Push Operation\n \t2.Pop operation\n\t3.Get Front\n\t4.Exit\n";
  cout<<"Enter Your Choice : ";
  cin>>choice;
  switch(choice)
  {
  case 1:
            cout<<"Enter Element to Insert : ";
            cin>>element;
            obj.push(element);
        break;
  case 2 :
            cout<<endl<<"Deleted element ="<<obj.pop()<<endl;
        break;
  case 3 :
            cout<<endl<<"Top= "<<obj.GetTop()<<endl;
            break;
  case 4:
            break;
  }
  }while(choice!=4);
  return 0;
 }