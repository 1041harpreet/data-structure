#include <iostream>
#include <unordered_map>
using namespace std;
void reverseArray(int *arr, int n)
{
    int temp;
    int i = 0;
    int j = n - 1;
    while (i < n / 2 || j > n / 2)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
void print(int *arr, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 4, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Reversing: ";
    print(arr, arr_size);
    reverseArray(arr, arr_size);
    cout << endl
         << "After Reverseing :";
    print(arr, arr_size);
    return 0;
}
//tc o(n) and space O(1)