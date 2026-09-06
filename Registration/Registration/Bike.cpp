#include "Bike.h"
#include <iostream>

using namespace std;

Bike::Bike()
{
}

Bike::Bike(string regNo, string model,
           string manufacturer, int year,
           string capacity)
    : Vehicle(regNo, model, manufacturer, year)
{
    EngineCapacity = capacity;
}

void Bike::displayInfo() const
{
    cout << formatInfo()
         << ", EngineCapacity: "
         << EngineCapacity
         << endl;
}

void Bike::writeBinary(ofstream &file) const
{
    int type = 2;
    file.write((char *)&type, sizeof(type));

    int length;

    length = RegistrationNumber.length();
    file.write((char *)&length, sizeof(length));
    file.write(RegistrationNumber.c_str(), length);

    length = ModelName.length();
    file.write((char *)&length, sizeof(length));
    file.write(ModelName.c_str(), length);

    length = Manufacturer.length();
    file.write((char *)&length, sizeof(length));
    file.write(Manufacturer.c_str(), length);

    file.write((char *)&Year, sizeof(Year));

    length = EngineCapacity.length();
    file.write((char *)&length, sizeof(length));
    file.write(EngineCapacity.c_str(), length);
}