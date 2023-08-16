//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int findLongestConseqSubseq(int arr[], int N)
    {
       sort(arr,arr+N);
       int ans=0;
       int count=0;
       vector<int> v;
       v.push_back(arr[0]);
       for(int i=1;i<N;i++){
           if(arr[i] !=arr[i-1]){
               v.push_back(arr[i]);
           }
       }
       for(int i=0;i<v.size();i++){
           if(i>0 && v[i]==v[i-1]+1){
               count++;
           }else{
             count=1 ;
           }
           ans=max(count,ans);
       }
       return ans;
    }
};

// Time complexity: O(Nlog(N)), Time to sort the array is O(Nlog(N)).
// Auxiliary space: O(N). Extra space is needed for storing distinct elements.

//better
//1 using hashmap
//using priority queue
