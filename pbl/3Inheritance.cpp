/*Consider we want to store the information of different vehicles.
Create a class named Vehicle with two data member named mileage and price. Create its two
subclasses:
*Car with data members to store ownership cost, warranty (by years), seating capacity and fuel type
(diesel or petrol).
*Bike with data members to store the number of cylinders, number of gears, cooling type(air, liquid or
oil), wheel type(alloys or spokes) and fuel tank size(in inches).
Make another two subclasses Audi and Ford of Car, each having a data member to store the model type.
Next, make two subclasses Bajaj and TVS, each having a data member to store the make-type. Now,
store and print the information of an Audi and a Ford car (i.e. model type, ownership cost, warranty,
seating capacity, fuel type, mileage and price.).*/
#include<iostream>
using namespace std;
class vehicle
{ int mileage;
  int price;
  public:
  void get_veh()
  {cout<<"\nEnter Mileage : ";
  cin>>mileage;
  cout<<"Enter Price : ";
  cin>>price;
  }
  void display_veh()
  { cout<<"   Mileage     : "<<mileage<<endl;
   cout<<"   Price       : "<<price<<endl;
  }
  vehicle()
  {cout<<"\nConstructor of vehicle"<<endl;
  }
};

class car:virtual public vehicle
{int cost;
int s_capacity;
int warranty;
char fuel[10];
public:
 void get_Car()
  { //get_veh();
  cout<<"Enter Ownership Cost : ";
  cin>>cost;
  cout<<"Enter seating capacity : ";
  cin>>s_capacity;
  cout<<"Enter Warranty : ";
  cin>>warranty;
  cout<<"Enter Fuel Type : ";
  cin>>fuel;
  }
  void display_Car()
  {//display_veh();
    cout<<"   Ownership Cost   : "<<cost<<endl;
    cout<<"   seating Capacity : "<<s_capacity<<endl;
    cout<<"   Warranty         : "<<warranty<<endl;
    cout<<"   Fuel type        : "<<fuel<<endl;
  }
   car()
   { cout<<"Constructor of car"<<endl;
   }
 
 
};

class Bike:virtual public vehicle
{int cylinder;
int gears;
char cooling[10];
char wheel[10];
float Fuel_tank;
public:
  void get_bike()
  {//get_veh();
  cout<<"Enter no.of cylinder : ";
  cin>>cylinder;
  cout<<"Enter no.of gears: ";
  cin>>gears;
  cout<<"Enter cooling type (air, liquid or oil) : ";
  cin>>cooling;
  cout<<"Enter wheel type (alloys or spokes)  : ";
  cin>>wheel;
  cout<<"Enter fuel tank size (in inches): ";
  cin>>Fuel_tank;
  }
  void display_bike()
  { //display_veh();
    cout<<"    No. of cylinder : "<<cylinder<<endl;
    cout<<"    No. of gears    : "<<gears<<endl;
    cout<<"    cooling type   : "<<cooling<<endl;
    cout<<"    wheel type     : "<<wheel<<endl;
    cout<<"    fuel tank size  :"<<Fuel_tank<<endl;
   
  }
  Bike()
  {cout<<"Constructor of Bike"<<endl;
  }
};
class audi: public car
{ char model[10];
public:
void get_audi()
{get_veh();
get_Car();
cout<<"Enter model of Audi: ";
cin>>model;
cout<<endl;
}
void display_audi()
{display_veh();
display_Car();
cout<<"   model of Audi: "<<model<<endl;

}
       audi()
       {cout<<"Constructor of Audi"<<endl;
       }
};

class ford: public car
{ char model[10];
public:
void get_ford()
{get_veh();
get_Car();
cout<<"\nEnter model of ford: ";
cin>>model;
cout<<endl;
}
void display_ford()
{display_veh();
display_Car();
cout<<"   model of Ford: "<<model<<endl;

}
ford()
{cout<<"Constructor of Ford"<<endl;
}
};
class bajaj: public Bike
{
char make_type[10];
public:
void get_bajaj();
void display_bajaj();
   bajaj()
   {cout<<"Constructor of bajaj"<<endl;
   }

};
void bajaj::get_bajaj()
{get_veh();
 get_bike();
 cout<<"Enter Make Type :";
 cin>>make_type;
}
void bajaj::display_bajaj()
{display_veh();
 display_bike();
 cout<<"    Make Type :"<<make_type<<endl;
 
}

class TVS:  public Bike
    { char Bmake_type[10];
         public:
               void get_TVS();
               void display_TVS();
            TVS()
            {
            cout<<"Constructor of TVS"<<endl;
           
            }
               
    };
void TVS::get_TVS()
  {   get_veh();
      get_bike();
      cout<<"Enter Make Type :";
      cin>>Bmake_type;
  }
void TVS::display_TVS()
  {     display_veh();
      display_bike();
      cout<<"   Make Type :"<<Bmake_type<<endl;
 
  }

int main()
{audi a;
ford f;
int choice;
TVS T;
bajaj B;

do
{
cout<<"Enter Your Vehice type: 1)Audi 2)Ford 3)TVS 4)Bajaj 5)Exit"<<endl;
cin>>choice;
switch(choice)
{  case 1 :
            cout<<"___________________ Enter data for Audi_________________________"<<endl;
            a.get_audi();
            cout<<"____________________ Data Display for Audi_______________________"<<endl;
            a.display_audi();
            break;
   case 2:  
           cout<<" __________________Enter data for Ford_______________________"<<endl;
           f.get_ford();
           cout<<"_________________ Data Display for Ford_______________________"<<endl;
           f.display_ford();    
           break;
   case 3:
          cout<<"_________________ Enter data for TVS_______________________"<<endl;
          T.get_TVS();
          cout<<"_________________ Data Display for TVS_______________________"<<endl;
          T.display_TVS();
          break;
   case 4:
          cout<<"_________________ Enter data for Bajaj_______________________"<<endl;
          B.get_bajaj();
          cout<<"_________________ Data display for Bajaj_______________________"<<endl;
          B.display_bajaj();      
          break;  
   case 5:
         break;            
}
}while(choice!=5);

return 0;
}
