#include <iostream>
#include <unordered_map>
using namespace std;
void pairSum(int arr[],int size,int s){
    int count=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)  {
            if(arr[i]+arr[j]==s){
                cout<<arr[i]<< " "<<arr[j]<<endl;
            }
        }
    }
    
}
int main()
{
    int arr[] = {1, 2, 3, 4,4, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    pairSum(arr, arr_size,5);
    return 0;
}