#include <iostream>
#include <cstring>
#include "Employee.h"

using namespace std;

Employee::Employee()
{
    empid = 0;
    empname = new char[1];
    empname[0] = '\0';
    basicSalary = 0;
}

Employee::Employee(int id, const char* name, double salary)
{
    empid = id;

    empname = new char[strlen(name) + 1];
    strcpy(empname, name);

    basicSalary = salary;
}

Employee::Employee(const Employee& e)
{
    empid = e.empid;

    empname = new char[strlen(e.empname) + 1];
    strcpy(empname, e.empname);

    basicSalary = e.basicSalary;
}

Employee::~Employee()
{
    delete[] empname;
}

// Setters

void Employee::setEmpid(int id)
{
    empid = id;
}

void Employee::setEmpname(const char* name)
{
    delete[] empname;

    empname = new char[strlen(name) + 1];
    strcpy(empname, name);
}

void Employee::setBasicSalary(double salary)
{
    basicSalary = salary;
}

// Getters

int Employee::getEmpid()
{
    return empid;
}

char* Employee::getEmpname()
{
    return empname;
}

double Employee::getBasicSalary()
{
    return basicSalary;
}

// Calculate salary using basic salary

double Employee::calculateSalary()
{
    return basicSalary;
}

// Calculate salary using basic salary + bonus

double Employee::calculateSalary(double bonus)
{
    return basicSalary + bonus;
}

// Calculate salary using basic salary + bonus + overtime

double Employee::calculateSalary(double bonus, double overtime)
{
    return basicSalary + bonus + overtime;
}

// Calculate salary using hourly rate and hours worked

double Employee::calculateSalary(double hourlyRate, int hoursWorked)
{
    return hourlyRate * hoursWorked;
}

// >> operator

istream& operator>>(istream& in, Employee& e)
{
    char name[100];

    cout << "Enter Employee ID: ";
    in >> e.empid;

    cout << "Enter Employee Name: ";
    in >> name;

    e.setEmpname(name);

    cout << "Enter Basic Salary: ";
    in >> e.basicSalary;

    return in;
}

// << operator

ostream& operator<<(ostream& out, const Employee& e)
{
    out << "Employee ID: " << e.empid << endl;
    out << "Employee Name: " << e.empname << endl;
    out << "Basic Salary: " << e.basicSalary << endl;

    return out;
}