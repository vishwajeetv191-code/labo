#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee
{
private:
    int empid;
    char* empname;
    double basicSalary;

public:
    //default constructor
    Employee();

    //parameterised constructor
    Employee(int id, const char* name, double salary);

    //copy constructor
    Employee(const Employee& e);
    //Destructor
    ~Employee();

    void setEmpid(int id);
    void setEmpname(const char* name);
    void setBasicSalary(double salary);

    int getEmpid();
    char* getEmpname();
    double getBasicSalary();

    // Function overloading
    double calculateSalary();
    double calculateSalary(double bonus);
    double calculateSalary(double bonus, double overtime);
    double calculateSalary(double hourlyRate, int hoursWorked);

    friend ostream& operator<<(ostream& out, const Employee& e);
    friend istream& operator>>(istream& in, Employee& e);
};

#endif