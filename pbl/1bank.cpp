#include <iostream>

using namespace std;
class Bank{
    char name[20];
    long Acc_no;
    int Balance;
    int Amount;
    public:
    void initialise(){
        cout<<"\nEnter Your Name : ";
        cin>>name;
        cout<<"\nEnter your Account Number : ";
        cin>>Acc_no;
        if((Acc_no)>9999999999)
        {
        cout<<"\nAccount Number Should be 10 digit"<<endl;
        cout<<"Enter Correct account number"<<endl;
        cin>>Acc_no;
        }
        cout<<"\nEnter Your Balance : ";
        cin>>Balance;
        cout<<endl;
    }
    void Deposit(){
        cout<<endl<<"\nYour Balance : "<<Balance;
        cout<<"\nEnter Amount To Deposit : ";
        cin>>Amount;
        cout<<"Your Amount Deposited Successfully !"<<endl;
        Balance= Balance + Amount;
        cout<<"New Balance : "<<Balance;
        cout<<endl;
    }
    void withdraw(){
        cout<<endl<<"\nYour Balance : "<<Balance;
        cout<<"Enter Amount To withdraw : ";
        cin>>Amount;
        if(Amount < Balance){
        cout<<"Your Amount withdraw Successfully !"<<endl;
        Balance= Balance - Amount;
        cout<<"New Balance : "<<Balance;}
        else{
            cout<<"Please Cheak Your Balance"<<endl;
           
        }
        cout<<endl;
    }
};

int main()
{
    Bank B;
    cout<<"_____________Welcome_______________ \n";
    B.initialise();
    int choice;
    do{
    cout<<"Enter Your Choice :1]Deposit 2]Withdraw 3]Exit"<<endl;
   
    cin>>choice;
    switch(choice){
    case 1:
        B.Deposit();
        break;
    case 2:
        B.withdraw();
         break;
    case 3:
        exit(0);
         break;        
         }
         }while(choice!=3);
         return 0;          
}

