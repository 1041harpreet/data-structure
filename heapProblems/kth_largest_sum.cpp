#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
//1 tc is O(n2logn) and space O(n2)
int getKthLargest(vector<int> &arr, int k)
{
	vector<int>v;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			v.push_back(sum);
		}
		
	}
	sort(v.begin(),v.end());
	return v[v.size()-k];
	
}
//using o(k) space 

int getKthLargest(vector<int> &arr, int k)
{
	//using min heap 
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=0;i<arr.size();i++){
		int sum=0;
		for(int j=i;j<arr.size();j++){
			sum+=arr[j];
			if(q.size()<k){
				q.push(sum);
			}else{
				if(sum > q.top()){
					q.pop();
					q.push(sum);
				}
			}
		}
	}
	return q.top();
}