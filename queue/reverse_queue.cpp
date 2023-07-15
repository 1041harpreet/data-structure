// using stack to reverse
// using recursion
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}
queue<int> rev(queue<int> q)
{
    if (q.size() == 0)
        return q;
    int element = q.front();
    q.pop();
    queue<int> qu = rev(q);
    qu.push(element);
    return qu;
}
int main()
{
    return 0;
}