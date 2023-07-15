#include<iostream>
#include<queue>
#include<stack>

using namespace std;
//1234 -> 1324
void interleaveHalf(queue<int>q){
    stack < int >s ; 
    int size=q.size();
    for (int i = 0; i < size/2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < size/2; i++)
    {
        q.push(q.front());
        q.pop();
    }
    
    for (int i = 0; i < size/2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        cout<<s.top()<<" ";
        cout<<q.front()<<" ";
        s.pop();
        q.pop();
    }
    
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    interleaveHalf(q);
    return 0;
}