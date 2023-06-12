#include<iostream>
using namespace std;
int  binarySearch(int arr[][4],int row,int col,int target){
    int start=0;
    int end=row*col-1;
    int mid=start+(end-start)/2;
    while (start <end)
    {
        int element=arr[mid/4][mid%4];
        if(element==target){
            return element;
        }
        if(element<target){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    cout<<binarySearch(arr,4,4,6);
    return 0;
}
