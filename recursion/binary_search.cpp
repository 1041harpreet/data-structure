#include<iostream>
using namespace std; 
int binarySearch(int arr[],int start,int end,int k){
  
    int mid=start+(end-start)/2;    //start+end/2

       
    if(start>=mid or end <=mid ){
        return -1;
    }
    if(arr[mid]==k){
        return mid;
    }
    if(arr[mid] > k){
        return binarySearch(arr,start,mid-1,k);
    }
    if(arr[mid] < k){
        return binarySearch(arr,mid+1,end,k);
    }
    return -1;
}
int main(){
    int arr[]={3,3,3,4,5,6,7,11,19,20};
    cout<<"element at : "<<binarySearch(arr,0,10,3)+1<<endl;
    return 0;
}