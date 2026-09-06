#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

// Default constructor
Student::Student()
{
    sid = 0;
    sname = new char[20];
    strcpy(sname, "Unknown");
    age = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
}

// Parameterized constructor
Student::Student(int id, const char* name, int a, float marks1,
                 float marks2, float marks3)
{
    sid = id;

    sname = new char[strlen(name) + 1];
    strcpy(sname, name);

    age = a;
    m1 = marks1;
    m2 = marks2;
    m3 = marks3;
}

// Setters
void Student::setSid(int id)
{
    sid = id;
}

void Student::setSname(const char* name)
{
    delete[] sname;

    sname = new char[strlen(name) + 1];
    strcpy(sname, name);
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setM1(float marks)
{
    m1 = marks;
}

void Student::setM2(float marks)
{
    m2 = marks;
}

void Student::setM3(float marks)
{
    m3 = marks;
}

// Getters
int Student::getSid()
{
    return sid;
}

char* Student::getSname()
{
    return sname;
}

int Student::getAge()
{
    return age;
}

float Student::getM1()
{
    return m1;
}

float Student::getM2()
{
    return m2;
}

float Student::getM3()
{
    return m3;
}

// Calculate percentage
float Student::calculate_percentage()
{
    return (m1 + m2 + m3) / 3;
}

// Calculate CGPA
float Student::calculate_cgpa()
{
    return ((1.0 / 3.0) * m1) +
           ((1.0 / 2.0) * m2) +
           ((1.0 / 4.0) * m3);
}

// Display
void Student::display()
{
    cout << "Student ID   : " << sid << endl;
    cout << "Student Name : " << sname << endl;
    cout << "Age          : " << age << endl;
    cout << "Marks 1      : " << m1 << endl;
    cout << "Marks 2      : " << m2 << endl;
    cout << "Marks 3      : " << m3 << endl;
    cout << "Percentage   : " << calculate_percentage() << endl;
     cout << "CGPA         : " << calculate_cgpa() << endl;
}