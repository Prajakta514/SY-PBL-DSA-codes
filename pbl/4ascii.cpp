//write a c++ program to check character and upper case, lower case ,digit or special character
#include<iostream>
using namespace std;
int main()
{
 char letter;
 cout<<"Enter Character to check its type"<<endl;
 cin>>letter;
 if(letter>=48 && letter<=57)
 { cout<<"Enter character is digit"<<endl;
 }
 else if(letter>=65  && letter<=90)
 {cout<<"Enter character is in upper case"<<endl;
 }
 else if(letter>=97  && letter<=122)
 {cout<<"Enter character is in lower case"<<endl;
 }

else if(letter==64 || letter==35 || letter==33 || letter == 96 || letter ==126 || letter ==38  ||letter ==42 ||letter ==36 || letter ==45 || letter ==95)
 {cout<<"Enter character is special character"<<endl;
 }
 else
 {cout<<"Enter character is of other type";}
  return 0;
  }

