//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//using two loops O(n2)
// bool isSubset(int arr1[], int arr2[], int m, int n)
// {
//     int i = 0;
//     int j = 0;
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             if (arr2[i] == arr1[j])
//                 break;
//         }
 
//         /* If the above inner loop was
//         not broken at all then arr2[i]
//         is not present in arr1[] */
//         if (j == m)
//             return 0;
//     }
 
//     /* If we reach here then all
//     elements of arr2[] are present
//     in arr1[] */
//     return 1;
// }

//sorting and merging
string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1,a1+n);
    sort(a2,a2+m);
    int i=0; 
    int j=0;
    while (i<n && j<m){
        if(a1[i]==a2[j]){
            i++;
            j++;
        }
        else if(a1[i] > a2[j]){
            return "No";
        }
        else if(a1[i]<a2[j]){
            i++;
        }
    }
    if(j==m){
        return "Yes";
    }else{
        return "No";
    }
    
}
//TC O(mLog(m) + nLog(n))

//3 using sorting and binary search


// 4 using hashmap
// bool isSubset(int arr1[], int m, int arr2[], int n)
// {
 
//     // Using STL set for hashing
//     set<int> hashset;
 
//     // hashset stores all the values of arr1
//     for (int i = 0; i < m; i++) {
//         hashset.insert(arr1[i]);
//     }
 
//     // loop to check if all elements of arr2 also
//     // lies in arr1
//     for (int i = 0; i < n; i++) {
//         if (hashset.find(arr2[i]) == hashset.end())
//             return false;
//     }
//     return true;
// }
 

 //usiign set
//  check if size after both array push is same
//  unordered_set<int> s;
//     for (int i = 0; i < m; i++) {
//         s.insert(arr1[i]);
//     }
//     int p = s.size();
//     for (int i = 0; i < n; i++) {
//         s.insert(arr2[i]);
//     }
//     if (s.size() == p) {
//         cout << "arr2[] is subset of arr1[] "
//              << "\n";
//     }
//     else {
//         cout << "arr2[] is not subset of arr1[] "
//              << "\n";
//     }