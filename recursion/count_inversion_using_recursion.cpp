#include <iostream>
using namespace std;
int countInversion(int arr[], int n)
{
    int count = 0;
    if (n == 1)
    {
        return 0;
    }
    if (arr[0] > arr[1])
    {
        count++;
    }
    countInversion(arr, n);
}