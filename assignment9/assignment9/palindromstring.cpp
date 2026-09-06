#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    stack<char> s;

    cout << "Enter a string: ";
    cin >> str;

    // Push all characters into stack
    for(int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    // Compare original string with stack characters
    bool palindrome = true;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != s.top())
        {
            palindrome = false;
            break;
        }

        s.pop();
    }

    if(palindrome)
        cout << "String is Palindrome";
    else
        cout << "String is Not Palindrome";

    return 0;
}
