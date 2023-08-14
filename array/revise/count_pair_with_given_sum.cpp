//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==k){
                 cnt++;   
                }
            }
        }
        return cnt;
    }
};

