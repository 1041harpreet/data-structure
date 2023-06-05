#include<iostream>
using namespace std;
void insertionSort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int temp=arr[i];
        int j = i-1;
        for (j;j>= 0; j--)
        {
           if(arr[j]>temp){
            arr[j+1]=arr[j];
           }else{
            break;
           }
        }
        arr[j+1]=temp;
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}
int main(){
    int arr[]={1,5,2,8,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    return 0;
}