//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
          int ans_swaps = INT_MAX;
    int size = 0; // Initialize size to 0
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            size++;
        }
    }

    int swap = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > k) {
            swap++;
        }
    }
    ans_swaps = min(swap, ans_swaps);

    for (int i = size; i < n; i++) {
        if (arr[i - size] > k) {
            swap--;
        }
        if (arr[i] > k) {
            swap++;
        }
        ans_swaps = min(ans_swaps, swap);
    }
    return ans_swaps;
        
    }
};
