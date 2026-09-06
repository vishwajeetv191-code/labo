#include <iostream>
#include <cstring>
#include "Friend.h"

using namespace std;

Friend::Friend()
{
    id = 0;
    name = NULL;
    hobbies = NULL;
    hobbyCount = 0;
    mobno = NULL;
    mobCount = 0;
    email = NULL;
    bdate = NULL;
    address = NULL;
}

void Friend::accept()
{
    char temp[100];

    cout << "Enter Friend ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> ws;
    cin.getline(temp, 100);

    name = new char[strlen(temp) + 1];
    strcpy(name, temp);

    cout << "Enter number of hobbies: ";
    cin >> hobbyCount;

    hobbies = new char*[hobbyCount];

    for (int i = 0; i < hobbyCount; i++)
    {
        cout << "Enter Hobby " << i + 1 << ": ";
        cin >> ws;
        cin.getline(temp, 100);

        hobbies[i] = new char[strlen(temp) + 1];
        strcpy(hobbies[i], temp);
    }

    cout << "Enter number of mobile numbers: ";
    cin >> mobCount;

    mobno = new char*[mobCount];

    for (int i = 0; i < mobCount; i++)
    {
        cout << "Enter Mobile Number " << i + 1 << ": ";
        cin >> ws;
        cin.getline(temp, 100);

        mobno[i] = new char[strlen(temp) + 1];
        strcpy(mobno[i], temp);
    }

    cout << "Enter Email: ";
    cin >> ws;
    cin.getline(temp, 100);

    email = new char[strlen(temp) + 1];
    strcpy(email, temp);

    cout << "Enter Birth Date: ";
    cin.getline(temp, 100);

    bdate = new char[strlen(temp) + 1];
    strcpy(bdate, temp);

    cout << "Enter Address: ";
    cin.getline(temp, 100);

    address = new char[strlen(temp) + 1];
    strcpy(address, temp);
}

void Friend::display()
{
    cout << "\n-----------------------------";
    cout << "\nID       : " << id;
    cout << "\nName     : " << name;

    cout << "\nHobbies  : ";
    for (int i = 0; i < hobbyCount; i++)
    {
        cout << hobbies[i];
        if (i < hobbyCount - 1)
            cout << ", ";
    }

    cout << "\nMobile No: ";
    for (int i = 0; i < mobCount; i++)
    {
        cout << mobno[i];
        if (i < mobCount - 1)
            cout << ", ";
    }

    cout << "\nEmail    : " << email;
    cout << "\nBirth Date: " << bdate;
    cout << "\nAddress  : " << address;
    cout << "\n-----------------------------\n";
}

int Friend::getId()
{
    return id;
}

char* Friend::getName()
{
    return name;
}

bool Friend::hasHobby(char* hobby)
{
    for (int i = 0; i < hobbyCount; i++)
    {
        if (strcmp(hobbies[i], hobby) == 0)
        {
            return true;
        }
    }

    return false;
}

Friend::~Friend()
{
    delete[] name;
    delete[] email;
    delete[] bdate;
    delete[] address;

    for (int i = 0; i < hobbyCount; i++)
    {
        delete[] hobbies[i];
    }
    delete[] hobbies;

    for (int i = 0; i < mobCount; i++)
    {
        delete[] mobno[i];
    }
    delete[] mobno;
}