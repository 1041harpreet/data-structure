#include <iostream>
#include <stack>
using namespace std;
class queue
{
    stack<int> st1, st2;

public:
    void enqueue(int data)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(data);
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    void dequeue()
    {
        if (st1.empty())
        {
            cout << "empty";
        }
        else
        {
            cout << "popped element is" << st1.top() << endl;
            st1.pop();
        }
    }
};
int main()
{
    queue q = queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}