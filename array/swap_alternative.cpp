// array : 123456
// op : 214365
#include <iostream>
using namespace std;
void print(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
void swapAlternative(int arr[], int size)
{
    for (int i = 0; i < size; i+=2)
    {
        if (i+1 < size)
        {
            swap(arr[i],arr[i+1]);
        
            
        }
    }
    
    
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5};
    // int arr_size = sizeof(arr) / sizeof(arr[0]);
    swapAlternative(arr, 5);
    print(arr,5);
    return 0;
}