#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
    Employee e;

    // Accept employee details
    cin >> e;

    cout << "\nEmployee Details:\n";
    cout << e;

    double bonus;
    double overtime;
    double hourlyRate;
    int hoursWorked;

    // Basic salary
    cout << "\nSalary using basic salary: "
         << e.calculateSalary() << endl;

    // Basic salary + bonus
    cout << "\nEnter bonus: ";
    cin >> bonus;

    cout << "Salary using basic salary + bonus: "
         << e.calculateSalary(bonus) << endl;

    // Basic salary + bonus + overtime
    cout << "\nEnter overtime amount: ";
    cin >> overtime;

    cout << "Salary using basic salary + bonus + overtime: "
         << e.calculateSalary(bonus, overtime) << endl;

    // Hourly salary
    cout << "\nEnter hourly rate: ";
    cin >> hourlyRate;

    cout << "Enter number of hours worked: ";
    cin >> hoursWorked;

    cout << "Salary using hourly rate and hours worked: "
         << e.calculateSalary(hourlyRate, hoursWorked) << endl;

    return 0;
}