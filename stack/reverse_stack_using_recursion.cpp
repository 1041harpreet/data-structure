#include <iostream>
#include <stack>
using namespace std;
// void solve(stack<int> &inputStack, int count, int size)
// {
//     if (count == size )
//     {
//         return;
//     }
//     int num = inputStack.top();
//     inputStack.pop();
//     solve(inputStack, count + 1, size);
//     inputStack.push(num);
// }
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
void reverse(stack<int> &inputStack)
{
    // int count = 0;
    // solve(inputStack, count, size);
    if (inputStack.empty())
    {

        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    reverse(inputStack);
    insertAtBottom(inputStack, num);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}