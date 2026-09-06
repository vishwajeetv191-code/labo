#include "SavingAccount.h"

SavingAccount::SavingAccount()
    : Account()
{
    chequeBookNumber = 0;
}

SavingAccount::SavingAccount(int id, const char* fn, const char* ln, const char* mob, const char* mail, int p, double bal, int chequeNo): Account(id, fn, ln, mob, mail, p, bal, 4.0, 20000, "Saving")
{
    chequeBookNumber = chequeNo;
}

void SavingAccount::displaySpecificDetails()
{
    cout << "Cheque Book No.  : "
         << chequeBookNumber << endl;
}