#include "Booking.h"
#include <iostream>
#include <cstring>
using namespace std;

// Default constructor
Booking::Booking()
{
    bookingid = 0;
    source = new char[1];
    source[0] = '\0';
    destination = new char[1];
    destination[0] = '\0';
    distance = 0.0;
    fare = 0.0;
}

// Parameterized constructor with default values
Booking::Booking(int id, const char* src, const char* dest, double dist, double f)
{
    bookingid = id;
    source = new char[strlen(src) + 1];
    strcpy(source, src);
    destination = new char[strlen(dest) + 1];
    strcpy(destination, dest);
    distance = dist;
    fare = f;
}

// Copy constructor
Booking::Booking(const Booking& other)
{
    bookingid = other.bookingid;
    source = new char[strlen(other.source) + 1];
    strcpy(source, other.source);
    destination = new char[strlen(other.destination) + 1];
    strcpy(destination, other.destination);
    distance = other.distance;
    fare = other.fare;
}

// Destructor
Booking::~Booking()
{
    delete[] source;
    delete[] destination;
}

// Setters
void Booking::setBookingid(int id)
{
    bookingid = id;
}

void Booking::setSource(const char* src)
{
    delete[] source;
    source = new char[strlen(src) + 1];
    strcpy(source, src);
}

void Booking::setDestination(const char* dest)
{
    delete[] destination;
    destination = new char[strlen(dest) + 1];
    strcpy(destination, dest);
}

void Booking::setDistance(double dist)
{
    distance = dist;
}

void Booking::setFare(double f)
{
    fare = f;
}

// Getters
int Booking::getBookingid() const
{
    return bookingid;
}

const char* Booking::getSource() const
{
    return source;
}

const char* Booking::getDestination() const
{
    return destination;
}

double Booking::getDistance() const
{
    return distance;
}

double Booking::getFare() const
{
    return fare;
}

// Display function
void Booking::display() const
{
    cout << "Booking ID: " << bookingid << endl;
    cout << "Source: " << source << endl;
    cout << "Destination: " << destination << endl;
    cout << "Distance: " << distance << " km" << endl;
    cout << "Fare: $" << fare << endl;
}

// Calculate Fare Functions (Function Overloading)

// 1. Based on distance only ($5 per km)
double Booking::calculateFare()
{
    fare = distance * 5.0;
    return fare;
}

// 2. Based on distance and vehicle type
// Economy: $5/km, Premium: $8/km, SUV: $10/km
double Booking::calculateFare(const char* vehicleType)
{
    double ratePerKm = 5.0;  // Default rate
    
    if (strcmp(vehicleType, "Economy") == 0) {
        ratePerKm = 5.0;
    } else if (strcmp(vehicleType, "Premium") == 0) {
        ratePerKm = 8.0;
    } else if (strcmp(vehicleType, "SUV") == 0) {
        ratePerKm = 10.0;
    }
    
    fare = distance * ratePerKm;
    return fare;
}

// 3. Based on distance, vehicle type, and number of passengers
// Add $2 per extra passenger (more than 1)
double Booking::calculateFare(const char* vehicleType, int passengers)
{
    double baseFare = calculateFare(vehicleType);  // Get vehicle rate
    double passengerCharge = 0.0;
    
    if (passengers > 1) {
        passengerCharge = (passengers - 1) * 2.0;
    }
    
    fare = baseFare + passengerCharge;
    return fare;
}

// 4. Premium booking with additional service charges
// Adds 20% service charge for premium bookings
double Booking::calculateFare(const char* vehicleType, int passengers, bool isPremium)
{
    double baseFare = calculateFare(vehicleType, passengers);
    double serviceCharge = 0.0;
    
    if (isPremium) {
        serviceCharge = baseFare * 0.20;  // 20% premium service charge
    }
    
    fare = baseFare + serviceCharge;
    return fare;
}

// Operator overloading for output (<<)
ostream& operator<<(ostream& os, const Booking& b)
{
    os << "\n========== Booking Details ==========" << endl;
    os << "Booking ID: " << b.bookingid << endl;
    os << "Source: " << b.source << endl;
    os << "Destination: " << b.destination << endl;
    os << "Distance: " << b.distance << " km" << endl;
    os << "Fare: $" << b.fare << endl;
    os << "====================================\n" << endl;
    return os;
}

// Operator overloading for input (>>)
istream& operator>>(istream& is, Booking& b)
{
    cout << "Enter Booking ID: ";
    is >> b.bookingid;
    is.ignore();  // Ignore newline

    cout << "Enter Source: ";
    char src[100];
    is.getline(src, 100);
    b.setSource(src);

    cout << "Enter Destination: ";
    char dest[100];
    is.getline(dest, 100);
    b.setDestination(dest);

    cout << "Enter Distance (km): ";
    is >> b.distance;

    cout << "Enter Fare: $";
    is >> b.fare;

    return is;
}
