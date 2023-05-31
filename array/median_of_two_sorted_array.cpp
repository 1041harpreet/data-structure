// median of two sorted array

#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

void sort(int arr[], int size, int arr2[], int size2)
{
    int size3 = size + size2;
    int arr3[size3];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i< size && j <size2)
    {
        if (arr[i] < arr2[j])
        {
            arr3[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i <size)
    {
        arr3[k] = arr[i];
        i++;
        k++;
    }
    while (j <size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    int mid=(0+size3)/2;
    cout << "array median is" << arr3[mid]<< endl;
    // print(arr3, size3);
}
int main()
{
    int arr[] = {1, 2, 3, 1, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int arr2[] = {1,  7};
    int arr_size2 = sizeof(arr2) / sizeof(arr2[0]);
    sort(arr, arr_size, arr2, arr_size2);
    return 0;
}