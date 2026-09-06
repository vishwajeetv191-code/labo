#ifndef DEMATACCOUNT_H
#define DEMATACCOUNT_H

#include "Account.h"

class Share
{
private:
    char name[50];
    int numberOfShares;
    double buyingPrice;
    char purchaseDate[20];

    double sellingPrice;
    char sellingDate[20];

public:
    Share();

    Share(const char* n,
          int noOfShares,
          double buyPrice,
          const char* purchaseDt,
          double sellPrice,
          const char* sellingDt);

    void display();
};

class DematAccount : public Account
{
private:
    Share shares[20];
    int shareCount;

public:
    DematAccount();

    DematAccount(int id,
                 const char* fn,
                 const char* ln,
                 const char* mob,
                 const char* mail,
                 int p,
                 double bal);

    void addShare();

    void displaySpecificDetails() override;
};

#endif