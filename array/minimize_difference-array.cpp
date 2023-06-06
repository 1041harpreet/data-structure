#include <iostream>
using namespace std;
int getMinDiff(int arr[], int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int minDif = arr[end] - arr[start];
    for (start; start < n; start++)
    {
        
        if (arr[start] <= arr[mid])
        {
            arr[start] = arr[start] + k;
            cout << " start " << start << " value " << arr[start] << endl;
        }
        else
        {
            arr[start] = arr[start] - k;
            cout << " start " << start << " value " << arr[start] << endl;
        }
    }
    cout << "start " << arr[0] << endl;
    cout << "end " << arr[end] << endl;
    return arr[end] - arr[0];
}
int main()
{
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << getMinDiff(arr, n, k);
    return 0;
}