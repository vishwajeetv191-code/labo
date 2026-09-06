#ifndef PRACTICE_H
#define PRACTICE_H

class Employee()
{

    private:
    char* empname;
    int empid;
    double empsalary;

    public:
    Employee();

    Employee(const char* name, int id, double salary);

    Employee(const Employee& e);

    ~Employee();

    //setter
    void setName(const char* name);
    void setId(int id);
    void setSalary(double salary);

    //getter
    char* getName();
    int getId();
    double getSalary();

    //function overloading
    double calculateSalary();
    double calculateSalary(double bonus);
    double calculateSalary(double bonus, double overtime);
    double calculateSalary(double hourlyRate,int hoursWorked);



    //friend function for operator overloading

    friend ostream operator<<(ostream& out, const Employee& e);
    friend istream operator>>(istream& in, Employee& e);
};
#endif