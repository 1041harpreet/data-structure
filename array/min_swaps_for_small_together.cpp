// Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.
// Example:
// Input:  arr[] = {2, 1, 5, 6, 3}, k = 3
// Output: 1
// Explanation:
// To bring elements 2, 1, 3 together, swap element ‘5’ with ‘3’ such that final array will be arr[] = {2, 1, 3, 6, 5}

// Input:  arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5
// Output: 2
// given array has all positive vales and need to merge operation so that it becomes a palindrome
#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int minSwaps(int arr[], int size, int number)
{
    int swaps = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < number)
        {
        }
        else
        {
            int temp = arr[swaps];
            arr[swaps] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }

    return swaps;
}

int main()
{
    int arr[] = {3, 2, 7, 6, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout<<"no of swaps "<<minSwaps(arr,arr_size,5);
    return 0;
}