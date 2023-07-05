// #include <bits/stdc++.h>
// stack<int> pushAtBottom(stack<int>& myStack, int x)
// {
//     stack<int> ans;
//     ans.push(x);
//     stack<int>dummy;
//     while(!myStack.empty()){
//         int top=myStack.top();
//         dummy.push(top);
//         myStack.pop();
//     }
//      while(!dummy.empty()){
//         int top=dummy.top();
//         ans.push(top);
//         dummy.pop();
//     }
//     return ans;
// }
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
int main()
{
     stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    insertAtBottom(s,10);
     while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
