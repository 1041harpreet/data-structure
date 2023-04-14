#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void minAndMax(int arr[],int size){
    int min=arr[0] ;
    int max=arr[0];
    for (int i = 1; i < size; i++)
    {
    if(min>arr[i]){
        min=arr[i];
    }
    if(max<arr[i]){
        max=arr[i];
    }
      
    }
    cout << "The minimum element is " << min << endl;
    cout<<"the max element elemnt is "<<max<<endl;
}
int main()
{
    int arr[] = {1,2,6,4,5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    print(arr, arr_size);
    minAndMax(arr,arr_size);
    return 0;
}