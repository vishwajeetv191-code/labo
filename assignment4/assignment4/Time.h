#ifndef TIME_H
#define TIME_H
#include<iostream>
using namespace std;

class Time{
    
    private:
        int hours;
        int minutes;
        

    public:
        // Default constructor
        Time();

        // Parameterized constructor
        Time(int h, int m);

        // Copy constructor
        Time(const Time& other);

        // Destructor
        ~Time();

        // Setters
        void setHours(int h);
        void setMinutes(int m);
        

        // Getters
        int getHours() ;
        int getMinutes();
        

        // Display function
        void display();

    Time operator+(Time t);
    Time operator-(Time t);
    Time& operator=(Time t);
    Time& operator++();      // Prefix increment
    Time operator++(int);    // Postfix increment
    Time& operator--();      // Prefix decrement
    Time operator--(int);    // Postfix decrement
};

//         // Function overloading for adding time
//         Time addTime(const Time& t) const;

//         // Operator overloading for adding time
//         Time operator+(const Time& t) const;

//         // Operator overloading for output stream
//         friend ostream& operator<<(ostream& os, const Time& t);
// }

#endif // TIME_H
