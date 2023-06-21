#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int key)
{

    if (size == 0)
    {
        return -1;
    }
    if (arr[size - 1] == key)
    {

        return size - 1;
    }
    return linearSearch(arr, size - 1, key);
}
int main()
{
    int arr[] = {1, 1, 2, 4, 5};
    cout << "Element at index : " << linearSearch(arr, sizeof(arr) / sizeof(*arr), 1)+1<<endl;
    return 0;
}