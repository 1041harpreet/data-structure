// 	long long maxProduct(vector<int> arr, int n) {
//     // Initializing result
//     long long result = static_cast<long long>(arr[0]);

//     for (int i = 0; i < n; i++) {
//         long long mul = static_cast<long long>(arr[i]);
//         // traversing in current subarray
//         for (int j = i + 1; j < n; j++) {
//             mul *= static_cast<long long>(arr[j]);
//             // updating result every time
//             // to keep an eye over the maximum product
//             result = max(result, mul);
//         }
//         // updating the result for (n-1)th index.
//         result = max(result, mul);
//     }
//     return result;
// }


//using kadane algo.
// long long maxProduct(vector<int> arr, int n) {
//     long long max_ending_here = arr[0];
//     long long min_ending_here = arr[0];
//     long long max_so_far = arr[0];

//     for (int i = 1; i < n; i++) {
//         if (arr[i] < 0) {
//             swap(max_ending_here, min_ending_here);
//         }

//         max_ending_here = max(static_cast<long long>(arr[i]), max_ending_here * arr[i]);
//         min_ending_here = min(static_cast<long long>(arr[i]), min_ending_here * arr[i]);

//         max_so_far = max(max_so_far, max_ending_here);
//     }

//     return max_so_far;
// }