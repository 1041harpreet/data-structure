#include <iostream>
#include <stack>
using namespace std;
bool isReduntant(string str)
{
    // 1 if opening bracket or operator push into stack
    // 2 if closing bracket check operator present between opening and closing
    int n = str.length();
    stack<char> stk;
    for (int i = 0; i <= n; i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            stk.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isReduntant = true;
                while (stk.top() != '(')
                {
                    char top = stk.top();
                    if (top == '+' || top == '-' || top == '/' || top == '*')
                    {
                        isReduntant = false;
                    }
                    stk.pop();
                }
                if (isReduntant == true)
                {
                    return true;
                }
                stk.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str = "(a+b)";
    cout << isReduntant(str) << endl;
    return 0;
}