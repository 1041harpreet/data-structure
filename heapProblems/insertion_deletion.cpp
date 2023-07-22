#include <iostream>
using namespace std;
class heap
{

public:
    int arr[100];
    int index;

    heap()
    {
        arr[0] = -1;
        index = 0;
    }
    void insertion(int value)
    {
        index = index + 1;
        arr[index] = value;
        int i = index;
        while (i > 1)
        {
            if (arr[i] > arr[i / 2])
            {
                swap(arr[i], arr[i / 2]);
                i = i / 2;
            }
            else
            {
                return;
            }
        }
    }
    void display()
    {
        for (int i = 1; i <= index; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void deletefromHeap()
    {
        if (index == 0)
        {
            cout << "no element present" << endl;
            return;
        }
        // swap root with last node and remove the last node from array
        arr[1] = arr[index];
        --index;
        int i = 1;
        while (i < index)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < index && arr[leftIndex] > arr[i])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (rightIndex < index && arr[rightIndex] > arr[i])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};
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
    // heap h;
    // h.insertion(50);
    // h.insertion(55);
    // h.insertion(53);
    // h.insertion(52);
    // h.insertion(54);
    // h.display();
    // h.deletefromHeap();
    // cout<<endl;
    // h.display();
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
