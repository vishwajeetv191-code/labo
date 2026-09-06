#include "Service.h"

Service::Service()
{
    count = 0;
    nextAccountId = 1001;

    for (int i = 0; i < 100; i++)
    {
        accounts[i] = NULL;
    }
}

Service::~Service()
{
    for (int i = 0; i < count; i++)
    {
        delete accounts[i];
    }
}

Account* Service::findAccountById(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (accounts[i]->getAccountId() == id)
        {
            return accounts[i];
        }
    }

    return NULL;
}

void Service::addNewAccount()
{
    if (count >= 100)
    {
        cout << "Bank account storage is full.\n";
        return;
    }

    int type;

    cout << "\n===== ADD NEW ACCOUNT =====\n";
    cout << "1. Saving Account\n";
    cout << "2. Current Account\n";
    cout << "3. Demat Account\n";
    cout << "Enter account type: ";
    cin >> type;

    char fname[50];
    char lname[50];
    char mobile[15];
    char email[50];

    int pin;
    double balance;

    cout << "Enter first name: ";
    cin >> fname;

    cout << "Enter last name: ";
    cin >> lname;

    cout << "Enter mobile number: ";
    cin >> mobile;

    cout << "Enter email: ";
    cin >> email;

    cout << "Enter PIN: ";
    cin >> pin;

    cout << "Enter initial balance: ";
    cin >> balance;

    int id = nextAccountId++;

    if (type == 1)
    {
        if (balance < 20000)
        {
            cout << "Saving account requires minimum "
                 << "balance of 20000.\n";
            return;
        }

        int chequeNo;

        cout << "Enter cheque book number: ";
        cin >> chequeNo;

        accounts[count] =new SavingAccount(id, fname, lname, mobile, email, pin, balance,chequeNo);
    }
    else if (type == 2)
    {
        if (balance < 1000)
        {
            cout << "Current account requires minimum "
                 << "balance of 1000.\n";
            return;
        }

        int transactions;

        cout << "Enter transactions per day: ";
        cin >> transactions;

        accounts[count] = new CurrentAccount(id, fname, lname, mobile,email, pin,  balance,  transactions);
    }
    else if (type == 3)
    {
        accounts[count] =
            new DematAccount(id, fname,  lname,  mobile, email, pin, balance);
       char choice;

        cout << "Do you want to add shares? (y/n): ";
        cin >> choice;

        while (choice == 'y' || choice == 'Y')
        {
            DematAccount* demat =
                dynamic_cast<DematAccount*>(accounts[count]);

            demat->addShare();

            cout << "Add another share? (y/n): ";
            cin >> choice;
        }
    }
    else
    {
        cout << "Invalid account type.\n";
        return;
    }

    count++;

    cout << "\nAccount created successfully!\n";
    cout << "Account ID: " << id << endl;
}

void Service::displayBalance()
{
    int id;

    cout << "\nEnter account ID: ";
    cin >> id;

    Account* acc = findAccountById(id);

    if (acc == NULL)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "\nAccount ID : " << id << endl;
    cout << "Account Type : "
         << acc->getAccountType() << endl;

    cout << "Balance : "
         << acc->getBalance() << endl;
}

void Service::closeAccount()
{
    int id;

    cout << "\nEnter account ID to close: ";
    cin >> id;

    int index = -1;

    for (int i = 0; i < count; i++)
    {
        if (accounts[i]->getAccountId() == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Account not found.\n";
        return;
    }

    delete accounts[index];

    for (int i = index; i < count - 1; i++)
    {
        accounts[i] = accounts[i + 1];
    }

    accounts[count - 1] = NULL;

    count--;

    cout << "Account closed successfully.\n";
}

void Service::countAccountType()
{
    int choice;

    cout << "\n===== COUNT ACCOUNT =====\n";
    cout << "1. Saving Account\n";
    cout << "2. Current Account\n";
    cout << "3. Demat Account\n";

    cout << "Enter choice: ";
    cin >> choice;

    int total = 0;

    for (int i = 0; i < count; i++)
    {
        if (choice == 1 &&
            strcmp(accounts[i]->getAccountType(), "Saving") == 0)
        {
            total++;
        }
        else if (choice == 2 &&
                 strcmp(accounts[i]->getAccountType(), "Current") == 0)
        {
            total++;
        }
        else if (choice == 3 &&
                 strcmp(accounts[i]->getAccountType(), "Demat") == 0)
        {
            total++;
        }
    }

    if (choice >= 1 && choice <= 3)
    {
        cout << "Number of accounts: "
             << total << endl;
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

void Service::withdrawAmount()
{
    int id;
    int enteredPin;
    double amount;

    cout << "\nEnter account ID: ";
    cin >> id;

    Account* acc = findAccountById(id);

    if (acc == NULL)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (!acc->verifyPin(enteredPin))
    {
        cout << "Incorrect PIN.\n";
        return;
    }

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    acc->withdraw(amount);
}

void Service::depositAmount()
{
    int id;
    double amount;

    cout << "\nEnter account ID: ";
    cin >> id;

    Account* acc = findAccountById(id);

    if (acc == NULL)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter amount to deposit: ";
    cin >> amount;

    acc->deposit(amount);
}

void Service::changePin()
{
    int id;
    int oldPin;
    int newPin;

    cout << "\nEnter account ID: ";
    cin >> id;

    Account* acc = findAccountById(id);

    if (acc == NULL)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter old PIN: ";
    cin >> oldPin;

    if (!acc->verifyPin(oldPin))
    {
        cout << "Incorrect old PIN.\n";
        return;
    }

    cout << "Enter new PIN: ";
    cin >> newPin;

    acc->setPin(newPin);

    cout << "PIN changed successfully.\n";
}

void Service::displayAllAccounts()
{
    if (count == 0)
    {
        cout << "No accounts available.\n";
        return;
    }

    cout << "\n===== ALL ACCOUNTS =====\n";

    for (int i = 0; i < count; i++)
    {
        accounts[i]->display();
    }
}