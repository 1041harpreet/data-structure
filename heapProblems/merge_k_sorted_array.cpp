//1 add all array elements into new array (ans array) and sort this array.. tc(n*k(log(n*k))) and sc. O(n*k)
// we dont use property of sorted array , we are storing in random order

// 2.
#include <bits/stdc++.h> 
#include <queue>
#include<vector>
using namespace std;
class Info{
    public:
    int data;
    int i;
    int j;
    Info(int data,int i,int j){
        this->data=data;
        this->i=i;
        this->j=j;
    }
};
class compare{
public:
   bool operator()(Info* a,Info* b){
       return a->data> b->data;
   }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int>ans;
    priority_queue<Info*,vector<Info*>,compare> q;
    for(int i=0;i<k;i++){
        Info* temp=new Info(arr[i][0],i,0);
        q.push(temp);
    }
    while(q.size() > 0){
        Info* top=q.top();
        ans.push_back(top->data);
        q.pop();
        int a=top->i;
        int b=top->j;
        if(b+1 < arr[a].size()){
            Info* t=new Info(arr[a][b+1],a,b+1);
            q.push(t);
        }
    }
    return ans;
}
//T.C : O(n*k(log(k))) and space O(k)+O(n*k)