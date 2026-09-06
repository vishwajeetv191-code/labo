#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <cstring>
using namespace std;

class Account
{
protected:
    int accountId;
    char fname[50];
    char lname[50];
    char mobile[15];
    char email[50];
    int pin;

    double balance;
    double interestRate;
    double minimumBalance;
    char accountType[20];

public:
    Account();

    Account(int id, const char* fn, const char* ln,const char* mob, const char* mail,int p, double bal,double rate, double minBal, const char* type);

    virtual ~Account();

    int getAccountId();
    double getBalance();
    double getMinimumBalance();
    double getInterestRate();

    const char* getAccountType();

    bool verifyPin(int enteredPin);

    void setPin(int newPin);

    void deposit(double amount);

    virtual bool withdraw(double amount);

    virtual void display();

    virtual void displaySpecificDetails() = 0;
};

#endif