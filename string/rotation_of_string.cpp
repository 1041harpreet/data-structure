// check string is roation of another string using c++.
// two queues are used for this operation.
#include <iostream>
#include <queue>
using namespace std;
bool checkRotation(string a, string b)
{
    
    int lengthOfA = a.length();
    int lengthOfB = b.length();
    if(lengthOfA !=lengthOfB){
        return false;
    }
    queue<char> aQueue;
    queue<char> bQueue;
    for (int i = 0; i < lengthOfA; i++)
    {
        aQueue.push(a[i]);
    }
    for (int i = 0; i < lengthOfB; i++)
    {
        bQueue.push(b[i]);
    }
    while (lengthOfB--)
    {
       char temp=bQueue.front();
       bQueue.pop();
        bQueue.push(temp);
        if (aQueue == bQueue)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string a = "abcdc";
    string b = "dcbcc";
    if (checkRotation(a, b))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}