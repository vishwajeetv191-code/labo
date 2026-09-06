#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount : public Account
{
private:
    int chequeBookNumber;

public:
    SavingAccount();

    SavingAccount(int id,  const char* fn,  const char* ln,  const char* mob,  const char* mail,  int p,  double bal, int chequeNo);

    void displaySpecificDetails() override;
};

#endif