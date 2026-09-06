#include<iostream>
using namespace std;

const int rows = 3;
const int cols = 3;

// Accept data
void acceptdata(int arr[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "Enter number for row " << i
                 << " col " << j << endl;
            cin >> arr[i][j];
        }
    }
}

// Display data
void displayData(int arr[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << '\t';
        }

        cout << endl;
    }
}

// Find maximum number
void findMaximum(int arr[rows][cols])
{
    int max = arr[0][0];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }

    cout << "Maximum number = " << max << endl;
}

// Find minimum number
void findMinimum(int arr[rows][cols])
{
    int min = arr[0][0];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }

    cout << "Minimum number = " << min << endl;
}

// Find addition of all numbers
void findAddition(int arr[rows][cols])
{
    int sum = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            sum = sum + arr[i][j];
        }
    }

    cout << "Addition of all numbers = " << sum << endl;
}

// Find sum of each row
void sumOfEachRow(int arr[rows][cols])
{
    int sum;

    for(int i = 0; i < rows; i++)
    {
        sum = 0;

        for(int j = 0; j < cols; j++)
        {
            sum = sum + arr[i][j];
        }

        cout << "Sum of row " << i << " = " << sum << endl;
    }
}

// Find sum of each column
void sumOfEachColumn(int arr[rows][cols])
{
    int sum;

    for(int j = 0; j < cols; j++)
    {
        sum = 0;

        for(int i = 0; i < rows; i++)
        {
            sum = sum + arr[i][j];
        }

        cout << "Sum of column " << j << " = " << sum << endl;
    }
}

// Find row-wise maximum
void rowWiseMaximum(int arr[rows][cols])
{
    int max;

    for(int i = 0; i < rows; i++)
    {
        max = arr[i][0];

        for(int j = 1; j < cols; j++)
        {
            if(arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }

        cout << "Maximum of row " << i << " = " << max << endl;
    }
}

// Find column-wise maximum
void columnWiseMaximum(int arr[rows][cols])
{
    int max;

    for(int j = 0; j < cols; j++)
    {
        max = arr[0][j];

        for(int i = 1; i < rows; i++)
        {
            if(arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }

        cout << "Maximum of column " << j << " = " << max << endl;
    }
}


int main()
{
    int arr[rows][cols];
    int choice;

    do
    {
        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1. Accept Data" << endl;
        cout << "2. Display Data" << endl;
        cout << "3. Find Maximum Number" << endl;
        cout << "4. Find Minimum Number" << endl;
        cout << "5. Find Addition of All Numbers" << endl;
        cout << "6. Find Sum of Each Row" << endl;
        cout << "7. Find Sum of Each Column" << endl;
        cout << "8. Find Row-wise Maximum" << endl;
        cout << "9. Find Column-wise Maximum" << endl;
        cout << "0. Exit" << endl;
        cout << "===========================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                acceptdata(arr);
                break;

            case 2:
                displayData(arr);
                break;

            case 3:
                findMaximum(arr);
                break;

            case 4:
                findMinimum(arr);
                break;

            case 5:
                findAddition(arr);
                break;

            case 6:
                sumOfEachRow(arr);
                break;

            case 7:
                sumOfEachColumn(arr);
                break;

            case 8:
                rowWiseMaximum(arr);
                break;

            case 9:
                columnWiseMaximum(arr);
                break;

            case 0:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while(choice != 0);

    return 0;
}