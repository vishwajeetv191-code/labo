#include"Car.h"
#include"Vehical.h"

#include<iostream>
using namespace std;

Car :: Car(int h) : Vehical(h)
{
    parCharge = 100.0;
    extracharge = 30.0;
}

void Car:: display()
{
    //display form vehical.cpp
    Vehical::display();

    cout<<"Extra Charges:"<<calExtraCharges()<<endl;
    cout<<"Total Parking charges: "<<calculateCharges()<<endl;
    cout<<"Receipt generated : "<<receiptCount<<endl;
}

inline double Car:: calExtraCharges()
{
    if(hours>3)
    {
        return (hours-3)*extracharge;
    }
    else 
    {
        return 0.0;
    }
}

double Car:: calculateCharges()
{
    return parCharge + calExtraCharges();
}

Car::~Car(){

}