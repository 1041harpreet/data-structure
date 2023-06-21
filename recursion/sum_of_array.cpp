#include<iostream>
using namespace std;
int sumOfArray(int arr[],int size){
    int sum=0;
    // sum +=arr[0]+arr[1];
    if(size <=0){
        return 0;
    }
    if(size ==1){
        return arr[0];
    }
    return  arr[0] + sumOfArray(arr+1,size-1);

}
int main(){
    int arr[]={1,5,2,4,5};
    cout<<sumOfArray(arr,sizeof(arr)/sizeof(*arr));
    return 0;

}