#include "Account.h"

Account::Account()
{
    accountId = 0;

    strcpy(fname, "");
    strcpy(lname, "");
    strcpy(mobile, "");
    strcpy(email, "");
    strcpy(accountType, "");

    pin = 0;
    balance = 0;
    interestRate = 0;
    minimumBalance = 0;
}

Account::Account(int id, const char* fn, const char* ln, const char* mob, const char* mail, int p, double bal, double rate, double minBal, const char* type)
{
    accountId = id;

    strcpy(fname, fn);
    strcpy(lname, ln);
    strcpy(mobile, mob);
    strcpy(email, mail);
    strcpy(accountType, type);

    pin = p;
    balance = bal;
    interestRate = rate;
    minimumBalance = minBal;
}

Account::~Account()
{
}

int Account::getAccountId()
{
    return accountId;
}

double Account::getBalance()
{
    return balance;
}

double Account::getMinimumBalance()
{
    return minimumBalance;
}

double Account::getInterestRate()
{
    return interestRate;
}

const char* Account::getAccountType()
{
    return accountType;
}

bool Account::verifyPin(int enteredPin)
{
    return pin == enteredPin;
}

void Account::setPin(int newPin)
{
    pin = newPin;
}

void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
        return;
    }

    balance = balance + amount;

    cout << "Amount deposited successfully.\n";
    cout << "New balance: " << balance << endl;
}

bool Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
        return false;
    }

    if (balance - amount < minimumBalance)
    {
        cout << "Withdrawal not allowed.\n";
        cout << "Minimum balance required: " << minimumBalance << endl;
        return false;
    }

    balance = balance - amount;

    cout << "Amount withdrawn successfully.\n";
    cout << "Remaining balance: " << balance << endl;

    return true;
}

void Account::display()
{
    cout << "\n-----------------------------\n";
    cout << "Account ID       : " << accountId << endl;
    cout << "Account Type     : " << accountType << endl;
    cout << "First Name       : " << fname << endl;
    cout << "Last Name        : " << lname << endl;
    cout << "Mobile           : " << mobile << endl;
    cout << "Email            : " << email << endl;
    cout << "Balance          : " << balance << endl;
    cout << "Interest Rate    : " << interestRate << "%" << endl;
    cout << "Minimum Balance  : " << minimumBalance << endl;

    displaySpecificDetails();

    cout << "-----------------------------\n";
}