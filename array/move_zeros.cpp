#include<iostream>
using namespace std;
void moveZero(int arr[],int n){
    int i=0;
    for (int j = 0; j < n; j++)
    {
        if(arr[j] !=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

}
int main(){
    int arr[]={1,0,0,2,4,0};
    moveZero(arr,6);
    return 0;
}