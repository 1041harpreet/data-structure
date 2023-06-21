#include <iostream>
using namespace std;
// void swap(int arr[], int i, int j)
// {
//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }
void insertionSort(int *arr, int i, int n)
{
    // pick smallest element in every move and add to sorted list
    if (n == 0 or n == 1)
    {
        return;
    }
    
}
int main()
{
    int arr[] = {4,3,7,6,5};
    insertionSort(arr, 0, 5);
    cout << "Sorted array is : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}