#include<iostream>
using namespace std;
void selectionSort(int arr[],int size){
     for (int  i = 0; i < size-1; i++){
        int min=i;
        for (int  j = i+1; j < size; j++)
        {
            if(arr[j]<arr[min]){
                min=j;
            }
             
        }
        swap(arr[min],arr[i]);
       
     }
     for (int i = 0; i < size; i++)
     {
       cout<<arr[i]<<endl;
     }
     
    
     
     
}
int main(){
    int arr[]={6,2,8,4,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,size);
    return 0;
}