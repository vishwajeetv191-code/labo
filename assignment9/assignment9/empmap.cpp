#include <iostream>
#include <map>
#include <string>
using namespace std;

class Employee
{
public:
    int id;
    string name;

    Employee()
    {
        id = 0;
        name = "";
    }

    Employee(int id, string name)
    {
        this->id = id;
        this->name = name;
    }

    void display()
    {
        cout << "ID: " << id << " Name: " << name << endl;
    }
};

int main()
{
    map<int, Employee> employees;

    int choice;

    do
    {
        cout << "\n===== Employee Management =====" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee by ID" << endl;
        cout << "3. Display All Employees" << endl;
        cout << "4. Display Employee by ID" << endl;
        cout << "5. Display Employee by Name" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int id;
                string name;

                cout << "Enter Employee ID: ";
                cin >> id;

                cout << "Enter Employee Name: ";
                cin >> name;

                if(employees.find(id) != employees.end())
                {
                    cout << "Employee ID already exists!" << endl;
                }
                else
                {
                    Employee e(id, name);
                    employees[id] = e;

                    cout << "Employee added successfully!" << endl;
                }

                break;
            }

            case 2:
            {
                int id;

                cout << "Enter Employee ID to delete: ";
                cin >> id;

                if(employees.find(id) != employees.end())
                {
                    employees.erase(id);
                    cout << "Employee deleted successfully!" << endl;
                }
                else
                {
                    cout << "Employee not found!" << endl;
                }

                break;
            }

            case 3:
            {
                if(employees.empty())
                {
                    cout << "No employees available!" << endl;
                }
                else
                {
                    cout << "\nAll Employees:" << endl;

                    for(auto x : employees)
                    {
                        x.second.display();
                    }
                }

                break;
            }

            case 4:
            {
                int id;

                cout << "Enter Employee ID: ";
                cin >> id;

                auto it = employees.find(id);

                if(it != employees.end())
                {
                    it->second.display();
                }
                else
                {
                    cout << "Employee not found!" << endl;
                }

                break;
            }

            case 5:
            {
                string name;
                bool found = false;

                cout << "Enter Employee Name: ";
                cin >> name;

                for(auto x : employees)
                {
                    if(x.second.name == name)
                    {
                        x.second.display();
                        found = true;
                    }
                }

                if(!found)
                {
                    cout << "Employee not found!" << endl;
                }

                break;
            }

            case 6:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}