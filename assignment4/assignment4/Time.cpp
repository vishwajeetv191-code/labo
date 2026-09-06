#include"Time.h"
#include<iostream>
using namespace std;

// Default constructor
Time::Time()
{
    hours = 0;
    minutes = 0;
}
// Parameterized constructor
Time::Time(int h, int m)
{ 
    
    hours = h;
    minutes = m;

    //Normalize the time if minutes exceed 60
    hours = hours + minutes / 60;
    minutes = minutes % 60;
}

// Copy constructor
Time::Time(const Time& other)
{
    hours = other.hours;
    minutes = other.minutes;
}

// Destructor
Time::~Time()
{
    // Nothing to clean up for this class
}

//setters
void Time::setHours(int h)
{
    hours = h;
}
void Time::setMinutes(int m)
{
    minutes = m;
}

// Getters
int Time::getHours()
{
    return hours;
}
int Time::getMinutes()
{
    return minutes;
}
// Display function
void Time::display()
{
    cout << "Time: " << hours << " hours and " << minutes << " minutes" << endl;
}

//Addition operator overloading
Time Time::operator+(Time t)
{
    Time temp;
    temp.hours = hours + t.hours;
    temp.minutes = minutes + t.minutes;
    
    if (temp.minutes >= 60) {
        temp.hours += temp.minutes / 60;
        temp.minutes = temp.minutes % 60;
    }
    return temp;
}


//Subtraction operator overloading
Time Time::operator-(Time t)
{
    Time temp;
    temp.hours = hours - t.hours;
    temp.minutes = minutes - t.minutes;
    
    if (temp.minutes < 0) {
        temp.hours -= 1;
        temp.minutes += 60;
    }
    return temp;
}

// Assignment operator overloading
Time& Time::operator=(Time t)
{
    hours = t.hours;
    minutes = t.minutes;
    return *this;
}

//prefix increment operator overloading
Time& Time::operator++()
{
    minutes++;
    if (minutes >= 60) {
        hours++;
        minutes = 0;
    }
    return *this;
}

//postfix increment operator overloading
Time Time::operator++(int)
{
    Time temp = *this;
    minutes++;
    if (minutes >= 60) {
        hours++;
        minutes = 0;
    }
    return temp;
}

//prefix decrement operator overloading
Time& Time::operator--()
{
    minutes--;
    if (minutes < 0) {
        
        minutes = 59;
        hours--;
    }
    return *this;
}

//postfix decrement operator overloading
Time Time::operator--(int)
{
    Time temp = *this;
    minutes--;
    if (minutes < 0) {
        minutes = 59;
        hours--;
    }
    return temp;
}
