#include <bits/stdc++.h> 
#include<vector>
using namespace std;
void heapify(vector<int> &arr, int size, int index)
{
    int smallest = index;
    int left = index * 2+1;
    int right = index * 2 + 2;
    if (left < size && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < size && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swap(arr[smallest], arr[index]);
        heapify(arr, size, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    for(int i=arr.size()/2-1; i>=0;i--){
        heapify(arr,arr.size(),i);
    }
    return arr;
}
int main(){
    return 0;
}
//note this is 0 index approach that why it has +1 with index