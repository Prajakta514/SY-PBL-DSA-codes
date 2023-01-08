#include<iostream>
using namespace std;
class ADT
{
int row1,row2,col1,col2;
int mat1[4][4],mat2[4][4],add[4][4],sub[4][4],mult[4][4];
public:
    void get_data()
{
   try
{
cout<<"Enter number of rows for matrix 1 : ";
cin>>row1;
cout<<"Enter number of columns for matrix 2 : ";
cin>>col1;
cout<<"Enter number of rows for matrix 1 : ";
cin>>row2;
cout<<"Enter naumber of columns for matrix 2 : ";
cin>>col2;
if(row1>4 || row2>4 ||col1>4 ||col2>4)
{
throw exception();
//throw 1;
}
else if(col1!=row2)
{
    throw 1;
}
else
{
cout<<"Enter elments of matrix 1 : "<<endl;
for(int i=0;i<row1;i++)
{
for(int j=0;j<col1 ;j++)
{
cout<<"mat1["<<i<<"]["<<j<<"]:";
cin>>mat1[i][j];
}
}
cout<<"Enter Elements of  2nd matrix :"<<endl;
for(int i=0;i<row2;i++)
{
for(int j=0;j<col2 ;j++)
{
cout<<"mat2["<<i<<"]["<<j<<"]:";
cin>>mat2[i][j];
}
}
}
}
catch(exception &)
{
cout<<"EXCEPTION:Max size of row and column is 4\n"<<endl;
  get_data();
}
catch(int a)
{
    cout<<"Number of columns of mat1 should equal to no.of rows of mat2  \n";
    get_data();
}

}
void Add()
{   cout<<"ADDITION OF MATRIX : \n";
    for(int i=0;i<row2;i++)
    {
       
        for(int j=0;j<col2;j++)
       {    add[i][j]=0;
           add[i][j]=mat1[i][j]+mat2[i][j];
           cout<<add[i][j]<<"\t";
       }  
       cout<<endl;
    }
}

void Sub()
{   cout<<"SUBTRACTION OF MATRIX : \n";
    for(int i=0;i<row2;i++)
    {
       
        for(int j=0;j<col2;j++)
       {    add[i][j]=0;
           add[i][j]=mat1[i][j]-mat2[i][j];
           cout<<add[i][j]<<"\t";
       }  
       cout<<endl;
    }
}
void Mult()
{
    cout<<"MULTIPLICATION OF MATRIX : \n";
     for(int i=0;i<row2;i++)
    {
       
        for(int j=0;j<col2;j++)
       {
           mult[i][j]=0;
           for(int k=0;k<col2;k++)
           {
               mult[i][j]+=mat1[i][k]*mat2[k][j];
               
           }
           cout<<mult[i][j]<<"\t";
        }cout<<endl;
    }
}    
};

int main()
{
    int ch;
    ADT obj;
    obj.get_data();
    // obj.Add();
    // obj.Sub();
    // obj.Mult();
    do{
        cout<<"Menu:\n\t1.Matrix Addition\n\t2.Matrix Subtraction\n\t3.Matrix Multiplication\n\t4.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:obj.Add();
                    break;
            case 2: obj.Sub();
                    break;
            case 3:obj.Mult();
                    break;
            case 4:
                    break;        
        }
       
    }while(ch!=4);
return 0;
}  