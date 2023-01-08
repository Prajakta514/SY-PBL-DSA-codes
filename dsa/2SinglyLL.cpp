#include<iostream>
using namespace std;
class Node
   {    public:
              int data;
              Node *next;
   };
class Llist
    {   Node *head, *temp;
        public:
             void create();
             void display();
             Node * Get_node();
             void append(Node *);
             void Insert_at_pos(Node *Newnode ,int pos);
             void search();
             void delnode(int );
             void reverse();
             Llist()
                {
                    head=NULL;
                }
   };
void Llist ::  create()
   {     Node *Newnode;
      // Node *temp;
       char choice;
       while(1)
        {
              cout<<"Do you Want to Continue ? (Y/N) : ";
              cin>>choice;
             if(choice== 'N')
                 { 
                   break;
                 }
              Newnode=Get_node();
              append(Newnode);
      }
 } 
Node *Llist:: Get_node()
 {    Node * Newnode;
      Newnode = new Node;
      cout<<"Enter Data: ";
      cin>>Newnode->data;
      Newnode->next= NULL;
      return (Newnode);
 }
 void Llist::display()
 {     // Node *temp;
        temp=head;
    while(1)
    {
      if(temp==NULL)
         {     
             cout<<"Linked List Ended"<<endl;
              break;
         }
      else
         {
         cout<<temp->data <<" -> ";
         temp= (temp->next);
         }
 }
 }
 void Llist::append(Node *Newnode)
 {  
      if(head == NULL)
       {   head=Newnode;
           temp=head;
       }
     else
     {
         temp->next =Newnode;
         temp=temp->next;
     }
 }
 void Llist::Insert_at_pos( Node *Newnode ,int position)
{   Node *temp=head;
  // Node * Newnode;
   Newnode= new Node;
   cout<<"Enter Data";
   cin>>Newnode->data;
    int count=1,flag=1;
    if(position == 1)
      {
        Newnode->next=temp;
        head= Newnode;
      }
    else
    {
        while(count!=position-1)
        {
           temp=temp->next;
            if(temp==NULL)
            {
                flag=0;
                break;
            }
            count++;
        }
        if(flag==1)
        {
            Newnode->next=temp->next;
            temp->next=Newnode;
        }
        else
        {
            cout<<"Position Not Found";
        }
    }
}
 void Llist::delnode(int pos)
{
    Node*temp=head;
    Node*curr;
    int count=1,flag=1;
    if(pos == 1)
    {
        curr=head;
        head=head->next;
        delete curr;
    }
    else
    {   while(count!=(pos-1))
        {
           temp=temp->next;
            if(temp==NULL)
            {
                flag=0;
                break;
            }
            count++;
        }
    }
      if (flag==1){
            curr=temp->next;
            temp->next=curr->next;
            delete curr;}
}
  void Llist::search()
{   int var;
    cout<<"Enter Element to Search : ";
    cin>>var;
    int flag=0;
    Node *temp=head;
    while(temp!= NULL)
    {
        if(temp->data==var)
        {
            cout<<"Element Found "<<endl;
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
 void Llist ::reverse()
 {
     Node *prev = NULL;
     Node *nextt = NULL;
     Node *curr = head;
     while (curr != NULL)
     {
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
     }
  head = prev;
 }
int main()
{  Node*Newnode;
    Llist obj;
    int choice,position;
    do
    {
    cout<<"\nMenu: "<<endl;
    cout<<"\t1.Create \n\t2.Display\n\t3.Insert At specific position\n\t4.Delete Element\n\t5.Reverse\n\t6.Search\n\t7.Exit\n";
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {   case 1:
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
                obj.delnode(position);
                cout<<"Display After deletion : ";
                obj.display();
                break;
        case 5:
                cout<<"Displaying Reverse Linked List : ";
                obj.reverse();
                obj.display();
                break;
        case 6 :
                obj.search();
                break;
        case 7:
                break;
    }
    }while(choice!=7) ;
    return 0;
}