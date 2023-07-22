#include <iostream>
using namespace std;

void heapify(int arr[], int size, int index)
{
    int largest = index;
    int left = index * 2;
    int right = index * 2 + 1;
    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}
int main()
{

    int arr[] = {-1, 55, 53, 54, 50};
    int n = 4;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "array after heapify" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
