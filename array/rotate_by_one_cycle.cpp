//Cyclically rotate an array by one
#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void rotateArray(int arr[],int size){
    int last=arr[size-1];
    for(int i = size-1; i > 0; i--)
        {
            // int temp = arr[i];
            arr[i]=arr[i-1];
        }
        arr[0]=last;
        print(arr,size);
}

int main()
{
    int arr[] = {1, 2, 23, 0, 6, 11, 78, 4, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    // print(arr, arr_size);
    rotateArray(arr,arr_size);
    return 0;
}