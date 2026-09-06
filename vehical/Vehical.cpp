#include"Vehical.h"
#include<iostream>
#include<cstring>
using namespace std;

Vehical::Vehical(int h)
{
    hours = h;
}

int Vehical::receiptCount = 0;

void Vehical::display()
{
    std::cout << "Parking hours: " << hours << std::endl;
}

Vehical::~Vehical()
{
}
