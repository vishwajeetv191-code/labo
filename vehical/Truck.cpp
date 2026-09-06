#include"Truck.h"
#include"Vehical.h"
#include<iostream>
using namespace std;

Truck :: Truck(int h, bool hasDiscount) : Vehical(h)
{
    parCharge = 200.0;
    extracharge = 50.0;
    discount = hasDiscount;
}

void Truck:: display()
{
    Vehical::display();

    cout<<"Extra Charges:"<<extracharge<<endl;
    cout<<"Total Parking charges:"<<calExtraCharges()<<endl;
    cout<<"Receipt generated : "<<receiptCount<<endl;
}

inline double Truck:: calExtraCharges()
{
    if(hours>2)
    {
        return (hours-2)* extracharge;
    }

    return 0.0;
    
}

double Truck:: calculateCharges(double discountAmount)
{
    return calculateCharges() - discountAmount;
}

double Truck:: calculateCharges()
{
   return parCharge + calExtraCharges();
}

Truck::~Truck(){

}