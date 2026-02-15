#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return -1;
}

int main()
{

    string infix;
    cin >> infix;

    string postfix = {};

    stack<char> s;
    int length = infix.length();

    for (int i = 0; i < length; i++)
    {
        if (isalpha(infix[i]))
            postfix += infix[i];

        else if (infix[i] == '(')
            s.push(infix[i]);

        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            char ch = infix[i];
            while (!s.empty() && (precedence(s.top()) >= precedence(ch)) && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    
    cout << postfix << endl;

    return 0;
}