#include <iostream>
#include<fstream>
using namespace std;
class Emp
{
    private:
         int id,age;
         string name,dept;
         int salary;
    public:
        void add_Record();
        void display_record();
        void search_record();
        void update_record();
};
void Emp::add_Record()
{
        ofstream file;
        Emp ob;
        char ch;
       
        file.open("emp.txt",ios::app| ios::binary);
        do
        {
            cout<<"Enter Employee name: ";
            cin>>ob.name;
            cout<<"Enter Employee ID: ";
            cin>>ob.id;
            cout<<"Enter Employee age: ";
            cin>>ob.age;
            cout<<"Enter Employee department: ";
            cin>>ob.dept;
            cout<<"Enter Employee salary: ";
            cin>>ob.salary;

            file.write((char*)&ob, sizeof(ob));
           
            cout<<"Do you want to add more records(y/n): "; cin>>ch;
           
            }while(ch!='n');

    file.close();

}

void Emp:: display_record()
{
        ifstream file;
        Emp ob;
        file.open("emp.txt",ios::in| ios::binary);
       
        while(file.read((char*)&ob, sizeof(ob)))
        {
        cout<<"\n"<<ob.id<<"\t"<<ob.name<<"\t"<<ob.age<<"\t"<<ob.dept<<"\t"<<ob.salary;
        }
       
        file.close();

}

void Emp:: search_record()
{
        ifstream file;
        Emp ob;
        int ID,flag=0;
        file.open("emp.txt",ios::in| ios::binary);

        cout<<"\nenter ID for searching: ";
        cin>>ID;
       
        while(file.read((char*)&ob, sizeof(ob)))
        {
        if(ID==ob.id)
        {
        cout<<"\nRecord found!!";
        cout<<"Details are as follows:";
        cout<<"\nid\tname\tage\tdept\tsalary"<<endl;
        cout<<ob.id<<"\t"<<ob.name<<"\t"<<ob.age<<"\t"<<ob.dept<<"\t"<<ob.salary;
        flag=1;
        break;
        }
    }
    if(flag==0)
        cout<<"Record not found!! ";

    file.close();
}

void Emp:: update_record()
{
        fstream file;
        Emp ob;
        int ID,sal;
        int pos=0,flag=0;
        file.open("emp.txt",ios::in  | ios::binary);

        cout<<"\nEnter ID for updating salary: "; cin>>ID;

        while(file.read((char*)&ob, sizeof(ob)))
        {
        if(ob.id==ID)
            {
                file.seekp(pos*sizeof(ob),ios::beg);
                cout<<"Enter updated salary: ";
                cin>>ob.salary;
                file.write((char*)&ob, sizeof(ob));
                flag=1;
            break;
            }
        ++pos;
        }
        file.close();
if(flag==0)
    cout<<"Record not found\n";
else
{cout<<"record updated";
}


}

int main()
{
Emp obj;
obj.add_Record();
obj.display_record();
obj.search_record();
obj.update_record();
obj.display_record();

return 0;

}