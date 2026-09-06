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
Student::Student(int sid, const char* sname, int age,
                 float m1, float m2, float m3)
{
    this->sid = sid;

    this->sname = new char[strlen(sname) + 1];
    strcpy(this->sname, sname);

    this->age = age;
    this->m1 = m1;
    this->m2 = m2;
    this->m3 = m3;
}

// Setters
void Student::setSid(int sid)
{
    this->sid = sid;
}

void Student::setSname(const char* sname)
{
    delete[] this->sname;

    this->sname = new char[strlen(sname) + 1];
    strcpy(this->sname, sname);
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setM1(float m1)
{
    this->m1 = m1;
}

void Student::setM2(float m2)
{
    this->m2 = m2;
}

void Student::setM3(float m3)
{
    this->m3 = m3;
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

// Display
void Student::display()
{
    cout << "Student ID : " << sid << endl;
    cout << "Student Name : " << sname << endl;
    cout << "Age : " << age << endl;
    cout << "Marks 1 : " << m1 << endl;
    cout << "Marks 2 : " << m2 << endl;
    cout << "Marks 3 : " << m3 << endl;
}

// Calculate percentage
float Student::calculatePercentage()
{
    return (m1 + m2 + m3) / 3;
}