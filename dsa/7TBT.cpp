#include <iostream>
using namespace std;

class node
{
  public:
    int data;
    node*left,*right;
    int lbit,rbit;
};
class Tbt
   {  
      public:
        node*root,*head;
        Tbt()
        {
            root=NULL;
        }
        void create();
        void insert(node*,node*);
       // void inorder(node*,node*);
         void inorder();
};
void Tbt:: insert(node*root,node*temp)
{  
    if(temp->data < root->data)
    {
        if(root->lbit==0)
        {
            temp->left=root->left;
            temp->right=root;
             root->left=temp;
            root->lbit=1;
        }
        else
            insert(root->left,temp);
    }
   
    if(temp->data > root->data)
    {
        if(root->rbit==0)
        {
            temp->left=root;
            temp->right=root->right;
            root->right=temp;
            root->rbit=1;
        }
        else
            insert(root->right,temp);
    }
}

void Tbt:: inorder()
{cout<<"\n Inorder Display is : ";
    node*temp;//traversing
    temp=head->left;
   
    if(root==NULL)
    {
        cout<<"Tree is empty";
    }
    else
    {
    while(temp!=head){
        while(temp->lbit==1)
        {
            temp=temp->left;
        }
        cout<<temp->data<<" ->";
        while(temp->rbit==0)
        {
            temp=temp->right;    //up
            if(temp==head)
            return;
            cout<<temp->data<<" ->";
        }
        temp=temp->right;
    }
    cout<<"NULL";
    }
}
void Tbt::create()
{      char ans;
    node*temp;
do{
    temp=new node;
    cout<<"Enter data : ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    temp->lbit=temp->rbit=0;
    if(root==NULL)
    {
        root=temp;
        head=new node;
        head->data=999;
        head->right=head;
      //  head->rbit=1;
        head->left=root;
      //  head->lbit=1;
        root->left=head;
        root->right=head;
    }
    else
        insert(root,temp);
       
    cout<<"Do you want to insert more nodes(y/n)";
    cin>>ans;
   
    }while(ans!='n');
 
}

int main()
{
    Tbt t;
    node*head,*root;
    t.create();
    t.inorder();
    return 0;
}
