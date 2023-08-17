// bool subArrayExists(int arr[], int n)
// {
//     for (int i = 0; i < n; i++) {
       
//         // starting point of the sub arrray and
//         // sum is initialized with first element of subarray
//         // a[i]
//         int sum = arr[i];
//         if (sum == 0)
//             return true;
//         for (int j = i + 1; j < n; j++) {
           
//             // we are finding the sum till jth index
//             // starting from ith index
//             sum += arr[j];
//             if (sum == 0)
//                 return true;
//         }
//     }
//     return false;
// }
//nested Loop 


//2 using hashing
//   bool subArrayExists(int arr[], int n)
//     {
//         unordered_set<int> sumSet;
 
//     // Traverse through array
//     // and store prefix sums
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += arr[i];
 
//         // If prefix sum is 0 or
//         // it is already present
//         if (sum == 0 || sumSet.find(sum) != sumSet.end())
//             return true;
 
//         sumSet.insert(sum);
//     }
//     return false;
//     }