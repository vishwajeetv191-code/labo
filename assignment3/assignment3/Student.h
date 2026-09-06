#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
    int sid;
    char* sname;
    int age;
    float m1, m2, m3;

public:
    // Default constructor
    Student();

    // Parameterized constructor
    Student(int, const char*, int, float, float, float);

    // Setters
    void setSid(int);
    void setSname(const char*);
    void setAge(int);
    void setM1(float);
    void setM2(float);
    void setM3(float);

    // Getters
    int getSid();
    char* getSname();
    int getAge();
    float getM1();
    float getM2();
    float getM3();

    // Display
    void display();

    // Calculate percentage
    float calculate_percentage();
    float calculate_cgpa();
};

#endif