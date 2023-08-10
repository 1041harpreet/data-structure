// 1 find common , new array size both array-common 
//  and store first array element and from second array add only those who are not present ,end return k;
//   int findCommon(int arr[], int size, int arr2[], int size2)
//     {
//     int common = 0;
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size2; j++)
//         {
//             if (arr[i] == arr2[j])
//             {
//                 common++;
//             }
//         }
//     }
//     return common;
//     }
//     //Function to return the count of number of elements in union of two arrays.
//     int doUnion(int a[], int n, int b[], int m)  {
//         int common=findCommon(a,n,b,m);
//        return n+m-common;
//     }
// but TC is O(n^2)


// 2. using set to store unique 
//  set<int> s;
//     // Remove the duplicates from arr1[]
//     for (int i = 0; i < n; i++) {
//         s.insert(arr1[i]);
//     }
 
//     // Remove duplicates from arr2[]
//     for (int i = 0; i < m; i++) {
//         s.insert(arr2[i]);
//     }
 
//     // Loading set to vector
//     vector<int> vec(s.begin(), s.end());
 
//     return vec;

// TC : Time Complexity: O(m*log(m) + n*log(n)) where ‘m’ and ‘n’ are the size of the arrays
// Auxiliary Space: O(m + n)
// 3 using hashmap

//{ Driver Code Starts
//Initial template for C++

// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// //User function template in C++

// class Solution{
//     public:
  
//     //Function to return the count of number of elements in union of two arrays.
//     int doUnion(int a[], int n, int b[], int m)  {
//        unordered_map<int,int>mp;
//        for(int i=0;i<n;i++){
//            mp[a[i]]++;
//        }
//        for(int i=0;i<m;i++){
//            mp[b[i]]++;
//        }
//        return mp.size();
//     }
// };

// //{ Driver Code Starts.

// int main() {
	
// 	int t;
// 	cin >> t;
	
// 	while(t--){
	    
// 	    int n, m;
// 	    cin >> n >> m;
// 	    int a[n], b[m];
	   
// 	    for(int i = 0;i<n;i++)
// 	       cin >> a[i];
	       
// 	    for(int i = 0;i<m;i++)
// 	       cin >> b[i];
// 	    Solution ob;
// 	    cout << ob.doUnion(a, n, b, m) << endl;
	    
// 	}
	
// 	return 0;
// }
// } Driver Code Ends
// 4 sort element and insert one by one 
//  sort(arr1.begin(), arr1.end());
//     sort(arr2.begin(), arr2.end());
//     int i = 0;
//     int j = 0;
//     while(i < m && j < n){
//         if(arr1[i] < arr2[j]){
//             i++;
//         }
//         else if (arr2[j] < arr1[i]){
//             j++;
//         }
//         else{
//             cout<<arr2[j]<<" ";
//             i++;
//             j++;
//         }
//     }