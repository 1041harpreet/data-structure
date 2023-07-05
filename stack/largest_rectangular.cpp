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
        while (stk.top() != -1 && inputStack[stk.top()] >= curr)
        {
            stk.pop();
        }

        ans[i] = stk.top();
        stk.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(int inputStack[], int n)
{
    stack<int> stk;
    vector<int> ans(n);
    stk.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = inputStack[i];
        while (stk.top() != -1 && inputStack[stk.top()] >= curr)
        {
            stk.pop();
        }

        ans[i] = stk.top();
        stk.push(i);
    }
    return ans;
}
int largestRectangular(int heights[], int size)
{

    vector<int> next;
    vector<int> prev;
    int area = INT_MIN;
    next = nextSmallerElement(heights, size);
    prev = prevSmallerElement(heights, size);
    for (int i = 0; i < size; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = size;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(newArea, area);
    }
    return area;
}
int main()
{
    int heights[] = {1, 2, 3, 4, 5};
    int size = sizeof(heights) / sizeof(heights[0]);
    cout << largestRectangular(heights, size);
    return 0;
}