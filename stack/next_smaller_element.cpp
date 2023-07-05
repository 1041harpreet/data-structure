#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallerElement(int inputStack[], int n)
{
    stack<int> stk;
    vector<int> ans(n);
    stk.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = inputStack[i];
        while (stk.top() >= curr)
        {
            stk.pop();
        }

        ans[i] = stk.top();
        stk.push(curr);
    }
    return ans;
}
int main()
{
    int arr[] = {2, 4, 1, 5, 3};
    vector<int> v = nextSmallerElement(arr, 5);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}