#ifndef SERVICE_H
#define SERVICE_H

#include "SavingAccount.h"
#include "CurrentAccount.h"
#include "DematAccount.h"

class Service
{
private:
    Account* accounts[100];
    int count;
    int nextAccountId;

public:
    Service();

    ~Service();

    void addNewAccount();

    Account* findAccountById(int id);

    void displayBalance();

    void closeAccount();

    void countAccountType();

    void withdrawAmount();

    void depositAmount();

    void changePin();

    void displayAllAccounts();
};

#endif