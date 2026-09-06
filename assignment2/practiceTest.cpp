#include<iostream>
#include<cstring>
#include"practice.h"
using namespace std;

int main()
{
    //object by using default constructor
    Student s1;
    cout<<"Student 1: "<<endl;
    s1.Display();

    cout<<"Percentage of student 1 : "<<s1.calculatePercentage()<<endl;

    Student s2(1,"Priya",22,85,90,95);
     cout<<"\nStudent 2: "<<endl;
    s2.Display();
    cout<<"Percentage of student 2 : "<<s2.calculatePercentage()<<endl;

    Student s3;

    s3.setSid(2);
    s3.setSname("Mali");
    s3.setAge(23);
    s3.setM1(90);
    s3.setM2(99);
    s3.setM3(98);
     cout<<"\nStudent 3: "<<endl;
     s3.Display();
    cout<<"Percentage of student 3 : "<<s3.calculatePercentage()<<endl;

    return 0;
}

