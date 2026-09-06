#include "DematAccount.h"

Share::Share()
{
    strcpy(name, "");
    numberOfShares = 0;
    buyingPrice = 0;
    strcpy(purchaseDate, "");

    sellingPrice = 0;
    strcpy(sellingDate, "");
}

Share::Share(const char* n,
             int noOfShares,
             double buyPrice,
             const char* purchaseDt,
             double sellPrice,
             const char* sellingDt)
{
    strcpy(name, n);

    numberOfShares = noOfShares;
    buyingPrice = buyPrice;

    strcpy(purchaseDate, purchaseDt);

    sellingPrice = sellPrice;

    strcpy(sellingDate, sellingDt);
}

void Share::display()
{
    cout << "\nShare Name       : " << name << endl;
    cout << "Number of Shares : " << numberOfShares << endl;
    cout << "Buying Price     : " << buyingPrice << endl;
    cout << "Purchase Date    : " << purchaseDate << endl;
    cout << "Selling Price    : " << sellingPrice << endl;
    cout << "Selling Date     : " << sellingDate << endl;
}


// ---------------- DematAccount ----------------

DematAccount::DematAccount()
    : Account()
{
    shareCount = 0;
}

DematAccount::DematAccount(int id,
                           const char* fn,
                           const char* ln,
                           const char* mob,
                           const char* mail,
                           int p,
                           double bal)
    : Account(id, fn, ln, mob, mail,
              p, bal, 0.0, 0, "Demat")
{
    shareCount = 0;
}

void DematAccount::addShare()
{
    if (shareCount >= 20)
    {
        cout << "Maximum 20 shares allowed.\n";
        return;
    }

    char name[50];
    int number;
    double buyPrice;
    char purchaseDate[20];

    double sellPrice;
    char sellingDate[20];

    cout << "\nEnter share name: ";
    cin >> name;

    cout << "Enter number of shares: ";
    cin >> number;

    cout << "Enter buying price: ";
    cin >> buyPrice;

    cout << "Enter purchase date (DD-MM-YYYY): ";
    cin >> purchaseDate;

    cout << "Enter selling price: ";
    cin >> sellPrice;

    cout << "Enter selling date (DD-MM-YYYY): ";
    cin >> sellingDate;

    shares[shareCount] = Share(name,number, buyPrice,  purchaseDate,  sellPrice, sellingDate);

    shareCount++;

    cout << "Share added successfully.\n";
}

void DematAccount::displaySpecificDetails()
{
    cout << "Number of Shares : " << shareCount << endl;

    if (shareCount == 0)
    {
        cout << "No share details available.\n";
        return;
    }

    cout << "\n===== SHARE DETAILS =====\n";

    for (int i = 0; i < shareCount; i++)
    {
        cout << "\nShare " << i + 1 << endl;
        shares[i].display();
    }
}