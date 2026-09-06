#include <iostream>
using namespace std;

const int SIZE = 100;

// Accept array data
void acceptData(double arr[], int &n)
{
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i << ": ";
        cin >> arr[i];
    }
}

// Display array
void displayData(double arr[], int n)
{
    if (n == 0)
    {
        cout << "Array is empty." << endl;
        return;
    }

    cout << "Array elements: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << endl;
}

// Modify number at given position
void modifyNumber(double arr[], int n)
{
    int pos;
    double num;

    cout << "Enter position to modify (0 to " << n - 1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= n)
    {
        cout << "Invalid position." << endl;
        return;
    }

    cout << "Enter new number: ";
    cin >> num;

    arr[pos] = num;

    cout << "Number modified successfully." << endl;
}

// Delete given number
void deleteNumber(double arr[], int &n)
{
    double num;
    int pos = -1;

    cout << "Enter number to delete: ";
    cin >> num;

    // Search number
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        cout << "Number not found." << endl;
        return;
    }

    // Shift elements to left
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Number deleted successfully." << endl;
}

// Search a number
void searchNumber(double arr[], int n)
{
    double num;
    int pos = -1;

    cout << "Enter number to search: ";
    cin >> num;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        cout << "Number found at position: " << pos << endl;
    }
    else
    {
        cout << "Number not found." << endl;
    }
}

// Addition of all even numbers
void sumEven(double arr[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    { //typecast from double to int
        if ((int)arr[i] % 2 == 0)
        {
            sum = sum + arr[i];
        }
    }

    cout << "Addition of all even numbers = " << sum << endl;
}

// Check prime number
bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

// Display prime numbers and count
void displayPrime(double arr[], int n)
{
    int count = 0;

    cout << "Prime numbers: ";

    for (int i = 0; i < n; i++)
    {
        int num = (int)arr[i];

        if (arr[i] == num && isPrime(num))
        {
            cout << arr[i] << "\t";
            count++;
        }
    }

    cout << endl;
    cout << "Count of prime numbers = " << count << endl;
}

// Find maximum odd number
void maxOdd(double arr[], int n)
{
    double max;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        int num = (int)arr[i];

        if (arr[i] == num && num % 2 != 0)
        {
            if (!found)
            {
                max = arr[i];
                found = true;
            }
            else if (arr[i] > max)
            {
                max = arr[i];
            }
        }
    }

    if (found)
    {
        cout << "Maximum odd number = " << max << endl;
    }
    else
    {
        cout << "No odd number found." << endl;
    }
}

// Find nth maximum
void nthMaximum(double arr[], int n)
{
    int nth;

    cout << "Enter n: ";
    cin >> nth;

    if (nth <= 0 || nth > n)
    {
        cout << "Invalid n." << endl;
        return;
    }

    double temp[SIZE];

    // Copy array
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }

    // Sort in descending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (temp[i] < temp[j])
            {
                double t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    cout << nth << "th maximum number = "
         << temp[nth - 1] << endl;
}

int main()
{
    double arr[SIZE];
    int n = 0;
    int choice;

    do
    {
        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1. Accept Data" << endl;
        cout << "2. Display Data" << endl;
        cout << "3. Modify Number at Given Position" << endl;
        cout << "4. Delete Given Number" << endl;
        cout << "5. Search a Number" << endl;
        cout << "6. Addition of All Even Numbers" << endl;
        cout << "7. Display Prime Numbers and Count" << endl;
        cout << "8. Find Maximum Odd Number" << endl;
        cout << "9. Find Nth Maximum" << endl;
        cout << "0. Exit" << endl;
        cout << "===========================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                acceptData(arr, n);
                break;

            case 2:
                displayData(arr, n);
                break;

            case 3:
                modifyNumber(arr, n);
                break;

            case 4:
                deleteNumber(arr, n);
                break;

            case 5:
                searchNumber(arr, n);
                break;

            case 6:
                sumEven(arr, n);
                break;

            case 7:
                displayPrime(arr, n);
                break;

            case 8:
                maxOdd(arr, n);
                break;

            case 9:
                nthMaximum(arr, n);
                break;

            case 0:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}