#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close)
{
    if(open == '(' && close == ')')
        return true;

    if(open == '{' && close == '}')
        return true;

    if(open == '[' && close == ']')
        return true;

    return false;
}

int main()
{
    string str;
    stack<char> s;

    cout << "Enter brackets: ";
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // Opening bracket
        if(ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }

        // Closing bracket
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(s.empty())
            {
                cout << "Not Balanced";
                return 0;
            }

            if(!isMatching(s.top(), ch))
            {
                cout << "Not Balanced";
                return 0;
            }

            s.pop();
        }
    }

    if(s.empty())
        cout << "Balanced Parenthesis";
    else
        cout << "Not Balanced";

    return 0;
}
