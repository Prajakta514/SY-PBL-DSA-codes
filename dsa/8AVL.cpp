#include<iostream>
using namespace std;
class node
{
  public:
    int data,height;
    node*lchild,*rchild;
   
};
int max(int a,int b)
{
    return a>b?a:b;
}
int getheight(node*n)
{
    if(n==NULL)
        return 0;
    return n->height;    
}
int BF(node*n)
{ if(n==NULL)
        return 0;
 return (getheight(n->lchild)-getheight(n->rchild));
}
class avl
{
    public:
    node*root;
    avl()
    {
        root=NULL;
    }
   node* create(int key );
    node* insert(node*,int);
    void display(node*);
    node*Lrotation(node*);
    node*Rrotation(node*);
};
node* avl::create(int key)
{
    node*newnode;
    newnode=new node;
    newnode->data=key;
    newnode->lchild=newnode->rchild=NULL;
    newnode->height=1;
    return newnode;
}
node*avl ::insert(node*Node,int key)
{
    if(Node==NULL)
      return   (create(key));
     if(key<Node->data)
        Node->lchild=insert(Node->lchild,key);
   else
        Node->rchild=insert(Node->rchild,key);
       
       return Node;
       
        Node->height=1+max(getheight(Node->lchild),getheight(Node->rchild));
        int bf=BF(Node);
       
        if(bf>1 && Node->lchild->data >key)
            return Rrotation(Node);
       if(bf<1 && Node->lchild->data <key)
             return Lrotation(Node);
       if(bf>1 && Node->lchild->data <key)
      {   Node->lchild=Lrotation(Node->lchild);
          return Rrotation(Node);}
       if(bf<1 && Node->lchild->data>key)
       {   Node->rchild=Rrotation(Node->rchild);
          return Lrotation(Node);}
          return Node;
}

node  *avl::Rrotation(node*y)
{
    node*x,*t2;
    x=y->lchild;
    t2=x->rchild;
    x->rchild=y;
    y->lchild=t2;
    y->height=1+max(getheight(y->lchild),getheight(y->rchild));
     x->height=1+max(getheight(x->lchild),getheight(x->rchild));
       return x;
}
node *avl::Lrotation(node*x)
{
    node*y,*t2;
    y=x->rchild;
    t2=y->lchild;
   
    y->lchild=x;
    x->rchild=t2;
    y->height=1+max(getheight(y->lchild),getheight(y->rchild));
    x->height=1+max(getheight(x->lchild),getheight(x->rchild));
       return y;
}
void avl::display(node*root)
{
    if(root!=NULL)
    {
        display(root->lchild);
        cout<<root->data<<" ";
        display(root->rchild);
    }
}
int main()
{
    avl obj;
    node*root=NULL;
//   root=obj.insert(root,10);
//     root=obj.insert(root,5);
//     root=obj.insert(root,50);
//     root=obj.insert(root,25);
//   obj.display(root);
   char ch;
   int key;
   do{
       cout<<"Enter data for insertion : ";
       cin>>key;
       root=obj.insert(root,key);
       cout<<"Do you want to add more nodes?(y/N) :";
       cin>>ch;
   }while(ch!='n');
    obj.display(root);
    return 0;
}
