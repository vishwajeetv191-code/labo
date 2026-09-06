#include "Service.h"

int main()
{
    Service service;

    int choice;

    do
    {
        cout << "\n\n";
        cout << "====================================\n";
        cout << "          XYZ BANK SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add New Account\n";
        cout << "2. Display Account Balance by ID\n";
        cout << "3. Close Account\n";
        cout << "4. Count Account Type\n";
        cout << "5. Withdraw Amount\n";
        cout << "6. Deposit Amount\n";
        cout << "7. Change PIN\n";
        cout << "8. Display All Accounts\n";
        cout << "0. Exit\n";

        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            service.addNewAccount();
            break;

        case 2:
            service.displayBalance();
            break;

        case 3:
            service.closeAccount();
            break;

        case 4:
            service.countAccountType();
            break;

        case 5:
            service.withdrawAmount();
            break;

        case 6:
            service.depositAmount();
            break;

        case 7:
            service.changePin();
            break;

        case 8:
            service.displayAllAccounts();
            break;

        case 0:
            cout << "Thank you for using XYZ Bank.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}