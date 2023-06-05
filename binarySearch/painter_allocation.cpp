#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int size, int k, int mid)
{
    int st = 1;
    int pagesum = 0;
    for (int i = 0; i < size; i++)
    {
        if (pagesum + arr[i] <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            st++;
            if (st > k || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int start = 0;
    int end = 0;
    int size=boards.size();
    // int sum=-1;
    for (int i = 0; i < size; i++)
    {
        end += boards[i];
    }
    int mid;
    int ans = -1;
    mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (isPossible(boards, size, k, mid))
        {

            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;

        }
        mid = start + (end - start) / 2;
       
    }
    return ans;
    
}
