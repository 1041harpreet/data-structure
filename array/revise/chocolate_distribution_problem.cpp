//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    long long dif=INT_MAX;
    sort(a.begin(),a.end());
    for(int i=0;i+m-1<n;i++){
        long long curr=a[i+m-1]-a[i];
        if(curr<dif){
            dif=curr;
        }
    }
    return dif;
    }   
};


//using priorty queue , using m size window