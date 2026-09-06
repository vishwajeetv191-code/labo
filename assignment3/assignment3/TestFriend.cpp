#include <iostream>
#include <cstring>
#include "Friend.h"

using namespace std;

int main()
{
    int n;

    cout << "Enter number of friends: ";
    cin >> n;

    Friend* friends = new Friend[n];

    int choice;

    do
    {
        cout << "\n========== FRIEND MENU ==========";
        cout << "\n1. Display All Friends";
        cout << "\n2. Search by ID";
        cout << "\n3. Search by Name";
        cout << "\n4. Display Friends with Particular Hobby";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                friends[i].display();
            }
            break;

        case 2:
        {
            int searchId;
            bool found = false;

            cout << "Enter ID to search: ";
            cin >> searchId;

            for (int i = 0; i < n; i++)
            {
                if (friends[i].getId() == searchId)
                {
                    friends[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Friend not found.\n";
            }

            break;
        }

        case 3:
        {
            char searchName[100];
            bool found = false;

            cout << "Enter name to search: ";
            cin >> ws;
            cin.getline(searchName, 100);

            for (int i = 0; i < n; i++)
            {
                if (strcmp(friends[i].getName(), searchName) == 0)
                {
                    friends[i].display();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "Friend not found.\n";
            }

            break;
        }

        case 4:
        {
            char searchHobby[100];
            bool found = false;

            cout << "Enter hobby to search: ";
            cin >> ws;
            cin.getline(searchHobby, 100);

            for (int i = 0; i < n; i++)
            {
                if (friends[i].hasHobby(searchHobby))
                {
                    friends[i].display();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "No friend found with this hobby.\n";
            }

            break;
        }

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    delete[] friends;

    return 0;
}