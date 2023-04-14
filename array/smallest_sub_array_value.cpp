//smallest sub array whose total is greater than given value
//note it should be continuous
//but only return length
//for eg
// Input:  {1, 2, 3, 4, 5, 6, 7, 8}, k = 20
// Output: The smallest subarray length is 3
// Explanation: The smallest subarray with sum > 20 is {6, 7, 8}
 
 
// Input:  {1, 2, 3, 4, 5, 6, 7, 8}, k = 7
// Output: The smallest subarray length is 1
// Explanation: The smallest subarray with sum > 7 is {8}
 
#include<iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void subArrayValue(int arr[],int size,int key){
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > key){

        }
    }
    
}
int main(){
    int arr[] = {1, -2, 6, -4, -5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    print(arr, arr_size);
    return 0;
}