#include "CurrentAccount.h"

CurrentAccount::CurrentAccount()
    : Account()
{
    transactionsPerDay = 0;
}

CurrentAccount::CurrentAccount(int id,  const char* fn,  const char* ln,  const char* mob, const char* mail, int p,  double bal, int transactions ): Account(id, fn, ln, mob, mail,  p, bal, 1.0, 1000, "Current")
{
    transactionsPerDay = transactions;
}

void CurrentAccount::displaySpecificDetails()
{
    cout << "Transactions/Day : "<< transactionsPerDay << endl;
}

void CurrentAccount::setTransactionsPerDay(int transactions)
{
    transactionsPerDay = transactions;
}

int CurrentAccount::getTransactionsPerDay()
{
    return transactionsPerDay;
}