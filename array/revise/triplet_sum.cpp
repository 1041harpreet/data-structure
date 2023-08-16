// using while loo and two pointer approach
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
 
    bool find3Numbers(int arr[], int size, int sum) {
        sort(arr, arr + size);

        for (int i = 0; i < size - 2; i++) {
            int pt1 = i + 1;
            int pt2 = size - 1;

            while (pt1 < pt2) {
                int currentSum = arr[i] + arr[pt1] + arr[pt2];
                if (currentSum == sum) {
                    return true;
                } else if (currentSum < sum) {
                    pt1++;
                } else {
                    pt2--;
                }
            }
        }

        return false;
    }

};

 bool findTriplet(int arr[], int n, int target, int count)
{
    // return true, if triplet has the desired sum.
    if (count == 3 && target == 0) {
        return true;
    }
 
    // if the sum is negative the current configuration, return false.
    if (count == 3 || n == 0 || target < 0) {
        return false;
    }
 
    // return again with including and excluding the current number
    return findTriplet(arr, n - 1, target - arr[n - 1], count + 1) ||
            findTriplet(arr, n - 1, target, count);
}
    bool find3Numbers(int A[], int n, int X)
    {
       bool ans=findTriplet(A,n,X,0);
       return ans;
    }