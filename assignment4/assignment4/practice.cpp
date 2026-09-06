#include"practice.h"
#include<iostream>
using namespace std;

Employee::Employee()
{
    id = 0;
    name = new char[1];
    name[0] = '\0';
    salary = 0;

}

Employee::Employee(const char* name,int id,double salary)
{
    empid = id;
    empname = new char[strlen(name)+1];
    strcpy(empname,name);

    empsalary = salary;
}

Employee::Employee(const Employee& e)
{
    empid = e.id;

    empname = new char[strlen(e.name)+1];
    strcpy(empname,e.name);

    empsalary = e.salary;
    
}

Employee::~Employee()
{
    delete[] empname;
}

istream& operator>>(istream& in,Employee& e)
{
    char name[100];

    cout<<"Enter Employee id: ";
    in>>e.empid;

    cout<<"Enter Employee name : ";
    in>>name;

    e.setEmpname(name);

    cout<<"Enter basic salary : ";
    in>>e.empsalary;

    return in;
}

ostream& operator<<(ostream& in,const Employee& e)
{
    out<<"Employee ID: "<<e.empid<<endl;
    out<<"Employee name: "<<e.empname<<endl;
    out<<"Employee Basic salary: "<<e.empsalary<<endl;

    return out;

}