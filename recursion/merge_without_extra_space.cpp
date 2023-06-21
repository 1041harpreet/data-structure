#include<iostream>
using namespace std;
void merge(int* arr, int start,int end)
{
    
    
}
void mergeSort(int* arr, int start, int end){
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    // merge
    merge(arr, start, end);
}
int main() {
    return 0;
}