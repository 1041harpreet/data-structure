#include <iostream>
#include <stack>
using namespace std;
bool isValid(string exp)
{
    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(exp[i]);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if (ch == ')')
                {
                    if (top == '(')
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if (ch == ']')
                {
                    if (top == '[')
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if (ch == '}')
                {
                    if (top == '{')
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }else{
        return false;
    }
    return true;
}
int main()
{
    string str="[{{}";
    cout<<isValid(str);
    return 0;
}