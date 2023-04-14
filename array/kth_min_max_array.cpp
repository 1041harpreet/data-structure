#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void kthMinAndMax(int arr[], int size, int k)
{
    int i, j, min, temp;
    for (i = 0; i < size; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    if (k <= 0 or k > size)
    {
        cout << "The " << k +1<< "th minimum element is " << arr[0] << endl;
        cout << "the " << k +1<< "th maximum element is " << arr[size - 1] << endl;
    }
    else
    {
        cout << "The " << k << "th minimum element is " << arr[k - 1] << endl;
        cout << "the " << k << "th maximum element is " << arr[size - k] << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 23, 0, 6, 11, 78, 4, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    // print(arr, arr_size);
    kthMinAndMax(arr, arr_size, 1);
    return 0;
}