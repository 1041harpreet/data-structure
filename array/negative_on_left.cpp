// move all negative element to left side of array
#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void negativeOnLeft(int arr[], int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

            j++;
        }
    }
}
int main()
{
    int arr[] = {1, -2, 6, -4, -5, 2, 6, -3, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    // print(arr, arr_size);
    negativeOnLeft(arr, arr_size);
    print(arr, arr_size);
    return 0;
}