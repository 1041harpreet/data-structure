//1 using map or vector wiht extra space

//in place 

// class Solution{
//     public:
//         //Function to merge the arrays.
//         void merge(long long arr1[], long long arr2[], int n, int m) 
//         { 
//             //put smaller in first array and greater element in second array 
//             //2 sort both arrays
//             int i=0,j=0,k=n-1;
//             while(i<=k && j<m){
//                 if(arr1[i] < arr2[j]){
//                     //first array elememt is smaller
//                     i++;
//                 }else{
//                     swap(arr2[j++],arr1[k--]);
//                 }
//             }
//             sort(arr1,arr1+n);
//             sort(arr2,arr2+m);
//         } 
// };
//TC : : O((N+M) * log(N+M))
//SC : O(1)

// C++ program for the above approach

// Time Complexity: O(M * (N * logN))
// Auxiliary Space: O(1)

// void merge(int arr1[], int arr2[], int n, int m)
// {
// 	int i = 0;
// 	// while loop till last element of array 1(sorted) is
// 	// greater than first element of array 2(sorted)
// 	while (arr1[n - 1] > arr2[0]) {
// 		if (arr1[i] > arr2[0]) {
// 			// swap arr1[i] with first element
// 			// of arr2 and sorting the updated
// 			// arr2(arr1 is already sorted)
// 			swap(arr1[i], arr2[0]);
// 			sort(arr2, arr2 + m);
// 		}
// 		i++;
// 	}
// }


