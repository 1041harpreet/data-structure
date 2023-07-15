// using stack to reverse
// using recursion
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
queue<int> rev(queue<int> q, int k)
{

    stack<int> s;
    int i = 0;
    while (i < k)
    {
        int element = q.front();
        q.pop();
        s.push(element);
        i++;
    }
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    for (int i = 0; i < q.size()-k; i++)
    {
        int top=q.front();
        q.pop();
        q.push(top);
    }
    
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    int k = 3;
   queue<int>a= rev(q, k);
   while (!a.empty())
   {
      cout<<a.front()<<" ";
      a.pop();
   }
   
    return 0;
}