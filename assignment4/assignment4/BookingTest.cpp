#include <iostream>
#include "Booking.h"
using namespace std;

int main()
{
    cout << "========== BOOKING SYSTEM - TRAVEL FARE CALCULATOR ==========" << endl;

    // 1. Create Booking using default constructor
    Booking b1;
    cout << "\n1. Default Constructor:" << endl;
    b1.display();

    // 2. Create Booking using parameterized constructor
    Booking b2(101, "New York", "Boston", 215.0);
    cout << "\n2. Parameterized Constructor:" << endl;
    b2.display();

    // 3. Create Booking using copy constructor
    Booking b3(b2);
    cout << "\n3. Copy Constructor (b3 = b2):" << endl;
    b3.display();

    // 4. Calculate Fare - Version 1 (Distance only)
    cout << "\n========== FARE CALCULATION - VERSION 1: Distance Only ==========" << endl;
    cout << "Booking Details: " << b2;
    double fare1 = b2.calculateFare();
    cout << "Calculated Fare (Distance only @ $5/km): $" << fare1 << endl;

    // 5. Calculate Fare - Version 2 (Distance + Vehicle Type)
    cout << "\n========== FARE CALCULATION - VERSION 2: Distance + Vehicle Type ==========" << endl;
    
    Booking b4(102, "Los Angeles", "San Diego", 120.0);
    cout << "Booking Details: " << b4;
    
    double fareEconomy = b4.calculateFare("Economy");
    cout << "Economy Vehicle Fare (@ $5/km): $" << fareEconomy << endl;
    
    double farePremium = b4.calculateFare("Premium");
    cout << "Premium Vehicle Fare (@ $8/km): $" << farePremium << endl;
    
    double fareSUV = b4.calculateFare("SUV");
    cout << "SUV Vehicle Fare (@ $10/km): $" << fareSUV << endl;

    // 6. Calculate Fare - Version 3 (Distance + Vehicle Type + Passengers)
    cout << "\n========== FARE CALCULATION - VERSION 3: Distance + Vehicle Type + Passengers ==========" << endl;
    
    Booking b5(103, "Chicago", "Milwaukee", 85.0);
    cout << "Booking Details: " << b5;
    
    double fare3a = b5.calculateFare("Economy", 1);
    cout << "Economy for 1 passenger: $" << fare3a << endl;
    
    double fare3b = b5.calculateFare("Premium", 3);
    cout << "Premium for 3 passengers (1 base + 2 extra @ $2 each): $" << fare3b << endl;
    
    double fare3c = b5.calculateFare("SUV", 5);
    cout << "SUV for 5 passengers (1 base + 4 extra @ $2 each): $" << fare3c << endl;

    // 7. Calculate Fare - Version 4 (Distance + Vehicle Type + Passengers + Premium Service)
    cout << "\n========== FARE CALCULATION - VERSION 4: Premium Booking with Service Charge ==========" << endl;
    
    Booking b6(104, "Miami", "Tampa", 280.0);
    cout << "Booking Details: " << b6;
    
    double fare4a = b6.calculateFare("Economy", 2, false);
    cout << "Economy for 2 passengers (No Premium): $" << fare4a << endl;
    
    double fare4b = b6.calculateFare("Economy", 2, true);
    cout << "Economy for 2 passengers (With 20% Premium Service Charge): $" << fare4b << endl;
    
    double fare4c = b6.calculateFare("Premium", 4, true);
    cout << "Premium for 4 passengers (With 20% Premium Service Charge): $" << fare4c << endl;

    // 8. Test Getters
    cout << "\n========== TESTING GETTERS ==========" << endl;
    cout << "Booking 2 Details:" << endl;
    cout << "  ID: " << b2.getBookingid() << endl;
    cout << "  Source: " << b2.getSource() << endl;
    cout << "  Destination: " << b2.getDestination() << endl;
    cout << "  Distance: " << b2.getDistance() << " km" << endl;
    cout << "  Fare: $" << b2.getFare() << endl;

    // 9. Test Setters
    cout << "\n========== TESTING SETTERS ==========" << endl;
    Booking b7(105, "Old Source", "Old Destination", 50.0);
    cout << "Original Booking:" << endl;
    b7.display();
    
    b7.setSource("Seattle");
    b7.setDestination("Portland");
    b7.setDistance(175.0);
    cout << "After setting new values:" << endl;
    b7.display();

    // 10. Test Operator Overloading (<<)
    cout << "\n========== TESTING OPERATOR << ==========" << endl;
    cout << b6;

    return 0;
}
