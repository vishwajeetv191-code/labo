#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account
{
private:
    int transactionsPerDay;

public:
    CurrentAccount();

    CurrentAccount(int id, const char* fn,  const char* ln, const char* mob,const char* mail,int p,  double bal, int transactions);

    void displaySpecificDetails() override;

    void setTransactionsPerDay(int transactions);

    int getTransactionsPerDay();
};

#endif