//1 two for loop , TC : O(n2)
//2 sort both array , traverse thorugh smaller and check then
// 3 use set to store first array elements and check the other array with this set if find then add to intersection array
// void printIntersection(int arr1[], int arr2[], int n1,
//                        int n2)
// {
//     set<int> hs;
 
//     // Insert the elements of arr1[] to set S
//     for (int i = 0; i < n1; i++)
//         hs.insert(arr1[i]);
 
//     for (int i = 0; i < n2; i++)
 
//         // If element is present in set then
//         // push it to vector V
//         if (hs.find(arr2[i]) != hs.end()) {
//             // erase element from set because if same
//             // element is present again in the array we
//             // don't need to count it again.
//             hs.erase(arr2[i]);
 
//             cout << arr2[i] << " ";
//         }
// }

// 4 two pointer approach

// int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
//     vector<int> intersection;
//     sort(a, a + n);
//     sort(b, b + m);
//     int i = 0;
//     int j = 0;
    
//     while (i < n && j < m) {
//         if (a[i] == b[j]) {
//             intersection.push_back(a[i]);
//             i++; // Increment either i or j, not both
//             // j++; <- Don't increment j here
//         } else if (a[i] > b[j]) {
//             j++;
//         } else {
//             i++;
//         }
//     }
    
//     return intersection.size();
// }