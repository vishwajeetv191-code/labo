#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <cstring>
using namespace std;

class Booking {
private:
    int bookingid;
    char* source;
    char* destination;
    double distance;
    double fare;

public:
    // Default constructor
    Booking();

    // Parameterized constructor with default values
    Booking(int id, const char* src = "Unknown", const char* dest = "Unknown", 
            double dist = 0.0, double f = 0.0);

    // Copy constructor
    Booking(const Booking& other);

    // Destructor
    ~Booking();

    // Setters
    void setBookingid(int id);
    void setSource(const char* src);
    void setDestination(const char* dest);
    void setDistance(double dist);
    void setFare(double f);

    // Getters
    int getBookingid() const;
    const char* getSource() const;
    const char* getDestination() const;
    double getDistance() const;
    double getFare() const;

    // Display function
    void display() const;

    // Function overloading for calculateFare
    double calculateFare();  // Based on distance only (5 per km)
    double calculateFare(const char* vehicleType);  // Based on distance and vehicle type
    double calculateFare(const char* vehicleType, int passengers);  // With number of passengers
    double calculateFare(const char* vehicleType, int passengers, bool isPremium);  // Premium booking

    // Operator overloading
    friend ostream& operator<<(ostream& os, const Booking& b);
    friend istream& operator>>(istream& is, Booking& b);
};

#endif // BOOKING_H
