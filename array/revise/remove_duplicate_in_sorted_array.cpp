// 1 check i+1 if i and i+1 equal remove i+1 
//crate new array and add only i element and leave i+1 but it is O(n)

// 2  using set store all element in set it only store uniqueu element

#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int> &arr, int n) {
	int j=0;
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[j]){
			j++;
			arr[j]=arr[i];
		}
	}
	return j+1;
}