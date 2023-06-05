#include <iostream>
using namespace std;
int pivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int binarySearch(int arr[], int s, int e, int k)
{
    int mid = s + (e - s) / 2;
 
    while (s <= e)
    {
        if (arr[mid] == k)
        {
          
            return mid;
        }
        else if (k > arr[mid])
        {
            s = mid + 1;
            
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
        
    }
    return -1;
}
int findElement(int arr[], int n, int element)
{
    int pv = pivot(arr, n);

    if (arr[pv] <= element && element <= arr[n - 1])
    {
        
      return  binarySearch(arr, pv, n - 1, element);
    }
    else
    {
       
       return binarySearch(arr, 0, pv - 1, element);
    }

    return -1;
}
int main()
{
    int arr[] = {7, 8, 9, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findElement(arr, size, 2);
    return 0;
}