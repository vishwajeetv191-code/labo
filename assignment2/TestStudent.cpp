#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    // Object using default constructor
    Student s1;

    cout << "Student 1:" << endl;
    s1.display();

    cout << "Percentage = "<< s1.calculatePercentage() << endl;


    // Object using parameterized constructor
    Student s2(101, "Priya", 21, 80, 85, 90);

    cout << "\nStudent 2:" << endl;
    s2.display();

    cout << "Percentage = "<< s2.calculatePercentage() << endl;


    // Object using setters
    Student s3;

    s3.setSid(102);
    s3.setSname("Rahul");
    s3.setAge(22);
    s3.setM1(70);
    s3.setM2(75);
    s3.setM3(80);

    cout << "\nStudent 3:" << endl;
    s3.display();

    cout << "Percentage = "
         << s3.calculatePercentage() << endl;

    return 0;
}