//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long waterStored=0;
        //check for all bars
        for(int i=1;i<n-1;i++){
            int left=arr[i];
            //find max left element from left side
            for(int j=0;j<i;j++){
                left = max(left, arr[j]);
            }
            int right=arr[i];
            //find max from right side
            for(int j=i+1;j<n;j++){
                right = max(right, arr[j]);
            }
            waterStored=waterStored+(min(left,right)-arr[i]);
        }
        return waterStored;
    }
};




//O(n) solution with space complexity;

// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n) {
        long long waterStored = 0;

        if (n <= 2) {
            return waterStored; // No water can be trapped with less than 3 blocks
        }

        vector<int> maxLeft(n), maxRight(n);

        // Pre-calculate the maximum heights on the left side of each element
        maxLeft[0] = arr[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
        }

        // Pre-calculate the maximum heights on the right side of each element
        maxRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], arr[i]);
        }

        // Calculate trapped water at each index based on pre-calculated max heights
        for (int i = 1; i < n - 1; i++) {
            int minMaxHeight = min(maxLeft[i], maxRight[i]);
            if (minMaxHeight > arr[i]) {
                waterStored += minMaxHeight - arr[i];
            }
        }

        return waterStored;
    }
};

// 3 more optimized O(n) with O(1) space complexity
//{ Driver Code Starts

class Solution{

    // Function to find the trapped water between the blocks.
    public:
      long long trappingWater(int arr[], int n) {
        long long waterStored = 0;

        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] > maxLeft) {
                    maxLeft = arr[left];
                } else {
                    waterStored += maxLeft - arr[left];
                }
                left++;
            } else {
                if (arr[right] > maxRight) {
                    maxRight = arr[right];
                } else {
                    waterStored += maxRight - arr[right];
                }
                right--;
            }
        }

        return waterStored;
    }
};


