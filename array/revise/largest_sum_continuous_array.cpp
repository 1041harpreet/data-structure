// Kadane algo (V.V.V.V.I.P)
//nested loops

//using recursion

// class Solution{
//     public:
//     // arr: input array
//     // n: size of array
//     //Function to find the sum of contiguous subarray with maximum sum.
//     long long maxSubarraySum(int arr[], int n){
        
//        // Base case: when there is only one element in the
//     // array
//     if (n == 1) {
//         return arr[0];
//     }
//     // Recursive case: divide the problem into smaller
//     // sub-problems
//     int m = n / 2;
//     // Find the maximum subarray sum in the left half
//     int left_max = maxSubarraySum(arr, m);
//     // Find the maximum subarray sum in the right half
//     int right_max = maxSubarraySum(arr + m, n - m);
//     // Find the maximum subarray sum that crosses the middle
//     // element
//     int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
//     for (int i = m; i < n; i++) {
//         sum += arr[i];
//         right_sum = max(right_sum, sum);
//     }
//     sum = 0;
//     for (int i = m - 1; i >= 0; i--) {
//         sum += arr[i];
//         left_sum = max(left_sum, sum);
//     }
//     int cross_max = left_sum + right_sum;
//     // Return the maximum of the three subarray sums
//     return max(cross_max, max(left_max, right_max));
//     }
// };


//but if result is negative it returns 0
// int maxSum(int arr[], int size)
// {
    // int max_sum = INT_MIN;
    // int cur_sum=0;
    // for (int i = 0; i < size - 1; i++)
    // {
    //     cur_sum += arr[i];
    //     if(cur_sum >max_sum){
    //         max_sum=cur_sum;
    //     }
    //     if (cur_sum <0)
    //     {
    //         cur_sum=0;
    //     }
    // }
    // return max_sum;
// }