#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int size, int count, int data)
{

    if (count == size)
    {
        inputStack.push(data);
        // inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, size, count + 1, data);
    inputStack.push(num);
}
void insertAtBottom(stack<int> &inputStack, int data)
{
    int size = inputStack.size();
    int count = 0;
    solve(inputStack, size, count, data);
}
void sortInsert(stack<int> &inputStack, int num)
{
    if (inputStack.empty() || (!inputStack.empty() && inputStack.top() < num))
    {
        inputStack.push(num);
        return;
    }
    int n = inputStack.top();
    inputStack.pop();
    sortInsert(inputStack, num);
    inputStack.push(n);
}
void sortStack(stack<int> &inputStack)
{
    if (inputStack.empty())
    {
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    sortStack(inputStack);
    sortInsert(inputStack, num);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    sortStack(s);
    // cout << s.size();
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}