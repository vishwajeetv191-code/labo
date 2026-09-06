#include <iostream>
using namespace std;

// Accept data
void accept(int **arr, int rows, int cols)
{
    cout << "Enter elements:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
}

// Display data
void display(int **arr, int rows, int cols)
{
    cout << "\n2D Array:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Find maximum number
int findMaximum(int **arr, int rows, int cols)
{
    int max = arr[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }

    return max;
}

// Find minimum number
int findMinimum(int **arr, int rows, int cols)
{
    int min = arr[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }

    return min;
}

// Find addition of all numbers
int findSum(int **arr, int rows, int cols)
{
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }

    return sum;
}

// Find sum of each row
void rowSum(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;

        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }

        cout << "Sum of Row " << i + 1 << " = " << sum << endl;
    }
}

// Find sum of each column
void columnSum(int **arr, int rows, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        int sum = 0;

        for (int i = 0; i < rows; i++)
        {
            sum += arr[i][j];
        }

        cout << "Sum of Column " << j + 1 << " = " << sum << endl;
    }
}

// Find row-wise maximum
void rowWiseMaximum(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        int max = arr[i][0];

        for (int j = 1; j < cols; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }

        cout << "Maximum of Row " << i + 1 << " = " << max << endl;
    }
}

// Find column-wise maximum
void columnWiseMaximum(int **arr, int rows, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        int max = arr[0][j];

        for (int i = 1; i < rows; i++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }

        cout << "Maximum of Column " << j + 1 << " = " << max << endl;
    }
}

int main()
{
    int rows, cols;
    int choice;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Dynamic allocation using int**
    int **arr = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Accept data\n";
        cout << "2. Display data\n";
        cout << "3. Find maximum number\n";
        cout << "4. Find minimum number\n";
        cout << "5. Find addition of all numbers\n";
        cout << "6. Find sum of each row\n";
        cout << "7. Find sum of each column\n";
        cout << "8. Find row-wise maximum\n";
        cout << "9. Find column-wise maximum\n";
        cout << "0. Exit\n";
        cout << "===========================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                accept(arr, rows, cols);
                break;

            case 2:
                display(arr, rows, cols);
                break;

            case 3:
                cout << "Maximum = "
                     << findMaximum(arr, rows, cols) << endl;
                break;

            case 4:
                cout << "Minimum = "
                     << findMinimum(arr, rows, cols) << endl;
                break;

            case 5:
                cout << "Addition of all numbers = "
                     << findSum(arr, rows, cols) << endl;
                break;

            case 6:
                rowSum(arr, rows, cols);
                break;

            case 7:
                columnSum(arr, rows, cols);
                break;

            case 8:
                rowWiseMaximum(arr, rows, cols);
                break;

            case 9:
                columnWiseMaximum(arr, rows, cols);
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}