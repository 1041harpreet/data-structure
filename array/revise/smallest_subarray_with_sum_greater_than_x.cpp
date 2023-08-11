//we can use two nested loops and store the sum if greater than x and check with ans if min

// int smallestSubWithSum(int arr[], int n, int x)
// {
//     //  Initialize length of smallest subarray as n+1
//      int min_len = n + 1;
 
//      // Pick every element as starting point
//      for (int start=0; start<n; start++)
//      {
//           // Initialize sum starting with current start
//           int curr_sum = arr[start];
 
//           // If first element itself is greater
//           if (curr_sum > x) return 1;
 
//           // Try different ending points for current start
//           for (int end=start+1; end<n; end++)
//           {
//               // add last element to current sum
//               curr_sum += arr[end];
 
//               // If sum becomes more than x and length of
//               // this subarray is smaller than current smallest
//               // length, update the smallest length (or result)
//               if (curr_sum > x && (end - start + 1) < min_len)
//                  min_len = (end - start + 1);
//           }
//      }
//      return min_len;
// }

// Time Complexity: O(n2).
// Auxiliary Space: O(1)


//2 using binary search , 
// Time Complexity: O (n log(n)).
// Auxiliary Space: O(n) 

//3 
// using  O(n) time
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int ans=n+1;
        int curr_sum=0;
        int start=0;
        int end=0;
        while(end<n){
            while(curr_sum<=x && end<n){
                curr_sum+=arr[end++];
            }
            // If current sum becomes greater than x.
            while(curr_sum >x && start<n){
                if(end-start<ans){
                    ans=end-start;
                }
                curr_sum-=arr[start++];
            }
        }
        return ans==n+1 ? 0 : ans;
    }
};

