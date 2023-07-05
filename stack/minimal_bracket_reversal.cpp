#include <iostream>
#include <stack>
using namespace std;
int minimalBracketReversal(string str)
{
    // odd wala case
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    // remove valid part
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (c == '{')
        {
            stk.push(c);
        }
        else
        {
            if (!stk.empty() && stk.top() == '{')
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
    }
    int a = 0;
    int b = 0;
    while (!stk.empty())
    {
        if (stk.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        stk.pop();
    }
    return (a+1)/2+(b+1)/2;
}
int main()
{
    string str = "{{}}}}";
    cout << "Minimum number of bracket reversals required: "<<minimalBracketReversal(str)<<endl;
    return 0;
}