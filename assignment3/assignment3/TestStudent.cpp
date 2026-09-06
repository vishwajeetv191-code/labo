#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    // 1. Object using default constructor
    Student s1;

    s1.setSid(101);
    s1.setSname("Priya");
    s1.setAge(22);
    s1.setM1(80);
    s1.setM2(85);
    s1.setM3(90);

    cout << "----- Student 1 -----" << endl;
    s1.display();

    // 2. Object using parameterized constructor
    Student s2(102, "Rahul", 21, 75, 80, 85);

    cout << "\n----- Student 2 -----" << endl;
    s2.display();

    // 3. Object using pointer
    Student* s3 = new Student();

    s3->setSid(103);
    s3->setSname("Amit");
    s3->setAge(23);
    s3->setM1(70);
    s3->setM2(78);
    s3->setM3(82);

    cout << "\n----- Student 3 -----" << endl;
    s3->display();

    delete s3;

    return 0;
}