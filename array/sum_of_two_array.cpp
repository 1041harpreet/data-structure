#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v,int n){
    int start=0;
    int end=n-1;
    while (start<end)
    {
        swap(v[start],v[end]);
        start++;
        end--;
    }
    return v;
}
vector<int> sumOfTwoArray(int arr[],int n,int arr2[],int m){
    // int sum[n];
    vector<int> v;
    int carry=0;
    int ans=0;
    int i=n-1,j=m-1;
    //basic case
    while (i >=0 && j >=0)
    {
        ans=arr[i]+arr2[j]+carry;
        carry=ans/10;
        ans=ans%10;
        v.push_back(ans);
        i--;
        j--;
    }
    //if array size greater than j
    while (i>=0)
    {
         ans=arr[i]+carry;
        carry=ans/10;
        ans=ans%10;
        v.push_back(ans);
        i--;
    }
    //if array size greater than i
    while (j>=0)
    {
         ans=arr2[j]+carry;
        carry=ans/10;
        ans=ans%10;
        v.push_back(ans);
        j--;
    }
    while (carry != 0)
    {
         ans=carry;
        carry=ans/10;
        ans=ans%10;
        v.push_back(ans);
    }
    
   return  reverse(v,v.size());
    
    
    
}
int main(){
    int arr[]={6,0,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int arr2[]={5,0,0,0};
    int m=sizeof(arr2)/sizeof(arr2[0]);
    vector<int> v=sumOfTwoArray(arr,n,arr2,m);
    // Iterating over all elements of vector
    for (auto elem : v) {
        cout << elem <<" ";
    }
    
    return 0;
}