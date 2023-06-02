#include<iostream>
using namespace std;
void SortOneTwo(int arr[],int size){
    int min =0;
    int mid=0;
    int max=size-1;
    while (mid<=max)
    {
        if(arr[mid]==0){
            swap(arr[min],arr[mid]);
            min++;
            mid++;
        }
        if(arr[mid]==2){
            swap(arr[mid],arr[max]);
            max--;
        }
        if(arr[mid]==1){
            mid++;
        }
       
    }
    
}
int main(){
    int arr[]={1,0,0,1,0,1,2,1,1,2,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    SortOneTwo(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i]<<" ";
    }
    return 0;
}