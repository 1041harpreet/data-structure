#include<iostream>
using namespace std;
void SortZeroOne(int arr[],int size){
    int min =0;
    int max=size-1;
    while (min<max)
    {
        if(arr[min]==0){
            min++;
        }
        if(arr[max]==1){
            max--;
        }
        if(arr[min]==1 & arr[max]==0){
            swap(arr[min],arr[max]);
            min++;
            max--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i]<<" ";
    }
}
int main(){
    int arr[]={1,0,0,1,0,1,1,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    SortZeroOne(arr,size);
    return 0;
}