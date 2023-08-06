#include <iostream>
#include <unordered_map>
using namespace std;
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
		if(mp[arr[i]]>1){
			return arr[i];
		}
	}
	
}

void print(int *arr, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << " Array : ";
    print(arr, arr_size);

    return 0;
}

