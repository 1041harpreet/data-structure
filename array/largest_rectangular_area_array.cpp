#include<iostream>
using namespace std;
int maxArea(int arr[],int n){
    int max_area=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int min_height=INT_MAX;
            for (int k = i; k <= j; k++)
            {
               min_height=min(min_height,arr[k]);
            }
            max_area=max(max_area,min_height*(j-i+1));
        }
        
    }
    return max_area;
    
}
int main(){
    int arr[]={1,1,2,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<" max area is : "<<maxArea(arr,n);
    return 0;
}