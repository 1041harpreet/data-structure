#include <iostream>
using namespace std;

bool isPossible(int arr[], int size, int student, int mid)
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
            if (st > student || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}
int allocateBook(int arr[], int size, int student)
{
    int start = 0;
    int end = 0;
    // int sum=-1;
    for (int i = 0; i < size; i++)
    {
        end += arr[i];
    }
    int mid;
    int ans = -1;
    mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (isPossible(arr, size, student, mid))
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
int main()
{
    int arr[] = {10, 20, 30, 40};
    int size = 4;
    cout << allocateBook(arr, size, 2);
    return 0;
}