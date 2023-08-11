// 1 using sort 012 method

//  void threeWayPartition(vector<int>& arr, int a, int b) {
//     int zeroP = 0;
//     int oneP = 0;
//     int twoP = arr.size() - 1;
    
//     while (oneP <= twoP) {
//         if (arr[oneP] > b) {
//             swap(arr[oneP], arr[twoP]);
//             twoP--;
//         } else {
//             if (arr[oneP] < a) {
//                 swap(arr[oneP], arr[zeroP]);
//                 zeroP++;
//             }
//             oneP++;
//         }
//     }
// }

//more optimzied code 

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
    int low = 0;
    int high = arr.size() - 1;
    int i = 0;
    
    while (i <= high) {
        if (arr[i] < a) {
            swap(arr[i], arr[low]);
            low++;
            i++;
        } else if (arr[i] > b) {
            swap(arr[i], arr[high]);
            high--;
        } else {
            i++;
        }
    }
}

};


// The time complexity of the algorithm is O(n), where n is the size of the input array.

// Space Complexity: The algorithm only uses a constant amount of extra space for variables (low, high, i). Thus, the space complexity is O(1), indicating constant space usage regardless of the size of the input array.