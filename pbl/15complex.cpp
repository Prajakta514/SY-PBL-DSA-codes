#include <iostream>

using namespace std;
class complex
{   public:
    int real,img;
   
            complex()
            {
                real=0;
                img=0;
            }
           
        complex operator +(complex c)
        {
            complex c3;
            c3.real=real+c.real;
            c3.img=img +c.img;
            return c3;
        }
        complex operator *(complex c)
        {
            complex c4;
            c4.real=(real*c.real)-(img*c.img);
            c4.img=(real*c.img)+(img*c.real);
            return c4;
        }
        friend istream &operator >>(istream &,complex & c);
       
         friend ostream &operator <<(ostream &,complex & c);
       
       
       
};

         istream &operator >>(istream &cin,complex & c)      
      {
        cout<<"\nEnter real part of complex Number : ";
        cin>>c.real;
        cout<<"Enter imaginary part of complex Number : ";
        cin>>c.img;
        return cin;
        }
        ostream &operator <<(ostream &cout,complex & c)
        {
        //cout<<"Real part ofcomplex Number : "<<c.real;
        //cout<<"Imaginary part of complex Number : "<<c.img;
        cout<<c.real<<"+"<<c.img<<"i";
       
        return cout;
        }
       

int main()
{    complex c3,c4,c5;
      cout<<c5;
      complex c1 ,c2;
      cin>>c1;
      cout<<"Complex Number c1 = ";
      cout<<c1;
      cout<<endl;
     
      cin>>c2;
      cout<<"Complex Number c2 = ";
      cout<<c2;
     
       c3=c1+c2;
       c4=c1*c2;
       cout<<endl;
       
       cout<<"\nAddition = ";
       cout<<c3;
       cout<<"\nMultiplication= ";
       cout<<c4;
 
    return 0;
}


 