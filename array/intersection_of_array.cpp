#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int arr[] = { 5, 6, 7, 8};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    return 0;
}

//  ans on leet code : 

// #include <bits/stdc++.h>
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2,
//                                   int m) {
//   int i = 0, j = 0;
//   vector<int> v;
//   while (i < n && j < m) {
//     if (arr1[i] < arr2[j])
//       i++;
//     else if (arr2[j] < arr1[i])
//       j++;
//     else /* if arr1[i] == arr2[j] */
//     {
// 		v.push_back(arr2[j]);
      
//       i++;
//       j++;
//     }
//   }
//   return v;
// }