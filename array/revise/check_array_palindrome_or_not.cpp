// //{ Driver Code Starts
// #include<iostream>
// #include<string.h>
// using namespace std;


// // } Driver Code Ends
// /*Complete the function below*/

// class Solution {
// public:
//     bool isPalindrome(int num) {
//     string str = to_string(num); // Convert the integer to a string
//     int length = str.length();
    
//     for (int i = 0; i < length / 2; i++) {
//         if (str[i] != str[length - 1 - i]) {
//             return false;
//         }
//     }
    
//     return true;
// }
//     int PalinArray(int a[], int n)
//     {
//     	for(int i=0;i<n;i++){
//     	    bool isPalin=isPalindrome(a[i]);
//     	    if(!isPalin){
//     	        return 0;
//     	    }
//     	}
//     	return 1;
//     }
// };

// //{ Driver Code Starts.

// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		int n;
// 		cin>>n;
// 		int a[n];
// 		for(int i = 0; i < n; i++)
// 			cin>>a[i];
// 		Solution obj;
// 		cout<<obj.PalinArray(a,n)<<endl;
// 	}
// }
// // } Driver Code Ends