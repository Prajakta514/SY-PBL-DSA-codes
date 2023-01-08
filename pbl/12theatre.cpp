#include <iostream>

using namespace std;


class dnode{
    public:
        int data;
        char book;
        dnode *next,*prev;
       
        dnode(){
            next=prev=NULL;
        }       
};

class dlist{
    dnode *head[15];
    public:
        dlist(){         
           for(int i=0;i<15;i++){
                head[i]=NULL;
            }
        }
        void insert(){
            int c=0;
            for(int i=0;i<15;i++){
                dnode *temp=head[i];
                for(int j=0;j<10;j++){
                   
                    dnode *seat=new dnode;
                    seat->data=++c;
                    seat->book='_';
                    if(head[i]==NULL){
                       head[i]=seat;
                       temp=seat;
                   }
                   else{
                       temp->next=seat;
                       seat->prev=temp;
                       temp=seat;
                   }
                   
               
                }
            }
        }
        void display(){
            for(int i=0;i<15;i++){
                dnode *temp=head[i];
                   
                for(int j=0;j<10;j++){
                    cout<<temp->book<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<"\n";
            }
        }
       
       
        void avail(){
            int sc=0;
             for(int i=0;i<15;i++){
                dnode *temp=head[i];
                   
                for(int j=0;j<10;j++){
                    if(temp->book=='B'){
                        sc+=1;
                    }
                    temp=temp->next;
                }
               
            }
            cout<<"seats booked: "<<sc<<endl;
        }
       
        void Book(int s){
            int f=0;
              for(int i=0;i<15;i++){
                dnode *temp=head[i];
                   
                for(int j=0;j<10;j++){
                    if(temp->data==s){
                      if(temp->book=='_'){
                       temp->book='B';
                       f=1;
                       break;
                      }
                     
                    }
                    temp=temp->next;
                }
               
            }
            if(f==0){
                          cout<<"\nalready booked\n";
                      }
        }
       
        void cancel(int s){
            int f=0;
            for(int i=0;i<15;i++){
                dnode *temp=head[i];
                   
                for(int j=0;j<10;j++){
                    if(temp->data==s){
                      if(temp->book=='B'){
                       temp->book='_';
                       f=1;
                       break;
                      }
                    }
                    temp=temp->next;
                }
               
            }
            if(f==0){
                cout<<"\nalready not booked\n";
            }
        }
};
int main()
{
    dlist d;
    d.insert();
    d.display();
    while(1){
        int c;
        cout<<"\n1.Check available Seats \n2. Book a seat\n3.Cancel Seat\n";
        cin>>c;
        
        if(c==1){
            d.avail();
        }
       
        else if(c==2){
            int s;
            cout<<"\n Enter which seat you want to book";
            cin>>s;
            d.Book(s);
            d.display();
        }
        else{
            int s;
            cout<<"\n Enter which seat you want to Cancel";
            cin>>s;
            d.cancel(s);
             d.display();
        }
        char ans;
        cout<<"Do You want to continue(Y/N)";
        cin>>ans;
        if(ans=='N')
        break;
    }

    return 0;
}
