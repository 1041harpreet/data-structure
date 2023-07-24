//1 using insertion sort and find median using /2 
//but in this starting complexity is O(n2)
#include <queue>
int signum(int a,int b){
	if(a==b){
		return 0;
	}
	else if(a>b){
		return 1;
	}
		return -1;
}
void callMedian(int element,int &median,priority_queue<int> &maxHeap,priority_queue<int,vector<int>,greater<int>>&minHeap,vector<int>ans){
	switch(signum(maxHeap.size(),minHeap.size())){
		case 0 : if(element >median){
			minHeap.push(element);
			median=minHeap.top();
		}else{
			maxHeap.push(element);
			median=maxHeap.top();
		}
		break;
		case 1 : if(element > median){
			minHeap.push(element);
			median=(maxHeap.top()+minHeap.top())/2;
		}else{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(element);
			median=(maxHeap.top()+minHeap.top())/2;
		}
		break;
		case -1 : if(element < median){
			maxHeap.push(element);
			median=(maxHeap.top()+minHeap.top())/2;
		}else{
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(element);
			median=(maxHeap.top()+minHeap.top())/2;
		}
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	vector<int>ans;
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>>minHeap;
	int median=0;
	for(int i=0;i<n;i++){
		callMedian(arr[i],median,maxHeap,minHeap,ans);
		ans.push_back(median);
	}
	return ans;
}
