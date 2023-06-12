// Algorithm
// Initialize two integers, low and high, which will initially contain the minimum element of the matrix and maximum element of the matrix, respectively.
// Iterate, while low is less than high.
// Calculate the middle integer (it might or might not be in the matrix) with the help of low and high.
// Count the number of elements in the arrays that are less than or equal to the middle.
// If the count is less than k, then the Kth smallest element will be in the second half, so we change low to middle+1.
// But if the count is greater than or equal to k, then the Kth smallest element will be in the first half, so we change high to mid.
// Finally, we return low

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// int kMin(int arr[][4], int row, int col, int k)
// {
//     vector<int> v;
//     for (int i = 0; i < row; i++){
//        for (int j = 0; j < col; j++)
//            {
//              v.push_back(arr[i][j]);
//            }
//     }

//     // sort the array and obtain k-th smallest element
//     sort(v.begin(), v.end());

//     return v[k - 1];
// }
int kMin(int arr[][4], int row, int col, int k)
{
    int start = arr[0][0];
    int end = arr[4][4];

    while (start < end)
    {
        int j = 15;
        int count = 0;
        int mid = start + (end - start) / 2;
        for (int i = 0; i < 16; i++)
        {
            while (j >= 0 && arr[i][j] > mid)
            {
                j--;
                        }
            count += (j + 1);
        }
        if (count < k)
            start = mid + 1;

        else
            end = mid;
    }
    return start;
}
int main(int argc, char const *argv[])
{
    int arr[4][4] = {
        {1, 2, 3, 4},
        {3, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    cout << kMin(arr, 4, 4, 4);
    // cout<<binarySearch(arr,4,4,6);
    return 0;
}
