//using map , vector and sort them
//2 min heap or priory queue
	// void sortedMerge(int a[], int b[], int res[],int n, int m)
	// {
	// // Concatenate two arrays
    // int i = 0, j = 0, k = 0;
    // while (i < n) {
    //     res[k] = a[i];
    //     i += 1;
    //     k += 1;
    // }
    // while (j < m) {
    //     res[k] = b[j];
    //     j += 1;
    //     k += 1;
    // }
 
    // // sorting the res array
    // sort(res, res + n + m);
	// }
//     Time Complexity: O ( (n + m) (log(n + m)) ) 
// Auxiliary Space: O ( (n + m) )


//4 sort both array and then merge
// void sortedMerge(int a[], int b[], int res[],
//                                 int n, int m)
// {
//     // Sorting a[] and b[]
//     sort(a, a + n);
//     sort(b, b + m);
 
//     // Merge two sorted arrays into res[]
//     int i = 0, j = 0, k = 0;
//     while (i < n && j < m) {
//         if (a[i] <= b[j]) {
//             res[k] = a[i];
//             i += 1;
//             k += 1;
//         } else {
//             res[k] = b[j];
//             j += 1;
//             k += 1;
//         }
//     }   
//     while (i < n) {  // Merging remaining
//                      // elements of a[] (if any)
//         res[k] = a[i];
//         i += 1;
//         k += 1;
//     }   
//     while (j < m) {   // Merging remaining
//                      // elements of b[] (if any)
//         res[k] = b[j];
//         j += 1;
//         k += 1;
//     }
// }

// Time Complexity: O (nlogn + mlogm + (n + m)) 
// Space Complexity: O ( (n + m) )

