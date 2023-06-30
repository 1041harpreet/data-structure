#include<iostream>
#include<vector>
 using namespace std;
 void solution(vector<int> arr,int index,vector<vector<int>>& ans , vector<int> output ){
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }
    //exclude 
    solution(arr,index+1,ans,output);
    //include
    output.push_back(arr[index]);
    solution(arr,index+1,ans,output);
 }
 vector<vector<int>> subset(vector<int> arr){
     vector<vector<int>> ans;
     vector<int> output;
     int index=0;
     solution(arr, index,ans,output);
     return ans;
 }