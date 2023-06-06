#include <iostream>
using namespace std;
void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
void rotateArray(int arr[], int n, int k)
{
 
    int start = 1;
    int j=0;
    while (start <= k)
    {
         int end=arr[n-1];
         for(int i=n-2;i>=0;i--){
            arr[i+1]=arr[i];
         }
         arr[0]=end;
         start++;
    }
    print(arr,n);
    
}
int main()
{
    int arr[]={1,2,3,4,5,1,2};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    rotateArray(arr,n,k);
    return 0;
}