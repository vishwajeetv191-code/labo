#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
    int sid;
    char* sname;
    int age;
    float m1;
    float m2;
    float m3;

public:
    // Default constructor
    Student();

    // Parameterized constructor
    Student(int sid, const char* sname, int age,
            float m1, float m2, float m3);

    // Setters
    void setSid(int sid);
    void setSname(const char* sname);
    void setAge(int age);
    void setM1(float m1);
    void setM2(float m2);
    void setM3(float m3);

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
    float calculatePercentage();
};

#endif