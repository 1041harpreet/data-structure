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
