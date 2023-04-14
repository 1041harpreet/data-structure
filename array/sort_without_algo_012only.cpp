#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void sort(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 0, 2, 0, 0, 2, 1, 1, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    sort(arr,arr_size);
    print(arr, arr_size);
    return 0;
}