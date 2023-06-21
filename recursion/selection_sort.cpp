#include <iostream>
using namespace std;
// void swap(int arr[], int i, int j)
// {
//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }
void selectionSort(int *arr, int i, int n)
{
    // pick smallest element in every move and add to sorted list
    if (n == 0 or n == 1)
    {
        return;
    }
 // find the minimum element in the unsorted subarray `[i…n-1]`
    // and swap it with `arr[i]`
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        // if `arr[j]` is less, then it is the new minimum
        if (arr[j] < arr[min]) {
            min = j;    // update the index of minimum element
        }
    }
 
    // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
    swap(arr[min],arr[i]);
 
    if (i + 1 < n) {
        selectionSort(arr, i + 1, n);
    }
}
int main()
{
    int arr[] = {4,3,7,6,5};
    selectionSort(arr, 0, 5);
    cout << "Sorted array is : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}