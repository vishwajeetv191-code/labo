#include<iostream>

using namespace std;
void acceptData(int **arr,int rows, int cols)
{
    // Implementation for accepting data
    for(int i=0; i<rows;i++)
    {
        for(int j=0; j<cols ; j++)
        {
            cout<<"Enter elements " <<i<<" "<<j<<endl;
            cin>>arr[i][j];
        }
    }
}

void displayData(int **arr, int rows, int cols)
{
     for(int i=0;i<rows;i++)
     {
         for(int j=0; j<cols ; j++)
         {
             cout<<arr[i][j]<<" ";
         }
         cout<<endl;
     }
}

int findMax(int **arr, int rows, int cols)
{
    int min_pos = arr[0][0];
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(arr[i][j]>min_pos)
            {
                min_pos=arr[i][j];
            }
        }
    }
    return min_pos;
}
int additionOfAll(int **arr, int rows, int cols)
{
    int sum=0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int SumofRow(int **arr, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        int sum=0;
        for(int j=0; j<cols; j++)
        {
            sum += arr[i][j];
        }
        cout<<"Sum of row "<<i<<" is: "<<sum<<endl;
    }
}

int SumofCol(int **arr, int rows, int cols)
{
    for(int j=0; j<cols; j++)
    {
        int sum=0;
        for(int i=0; i<rows; i++)
        {
            sum += arr[i][j];
        }
        cout<<"Sum of col "<<j<<" is: "<<sum<<endl;
    }
}

int rowwiseMax(int **arr, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        int max=arr[i][0];
        for(int j=0; j<cols; j++)
        {
            if(arr[i][j]>max)
            {
                max=arr[i][j];
            }
        }
        cout<<"Max of row "<<i<<" is: "<<max<<endl;
    }
}

int colwiseMax(int **arr, int rows, int cols)
{
    for(int j=0; j<cols; j++)
    {
        int max=arr[0][j];
        for(int i=0; i<rows; i++)
        {
            if(arr[i][j]>max)
            {
                max=arr[i][j];
            }
        }
        cout<<"Max of col "<<j<<" is: "<<max<<endl;
    }
}

int main()
{
    // Implementation for main function
    int rows, cols;
    cout<<"Enter number of rows: "<<endl;
    cin>>rows;

    cout<<"Enter number of cols: "<<endl;
    cin>>cols;

    int **arr = new int *[rows];
    for(int i=0; i<rows; i++)
    {
        arr[i] = new int[cols];
    }

    acceptData(arr, rows, cols);
    displayData(arr, rows, cols);
    return 0;
}
