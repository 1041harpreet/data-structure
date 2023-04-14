// Input: array[]= {5, 10, 20, 15}
// Output: 20
// Explanation: The element 20 has neighbors 10 and 15, both of them are less than 20.

// Input: array[] = {10, 20, 15, 2, 23, 90, 67}
// Output: 20 or 90
// Explanation: The element 20 has neighbors 10 and 15, both of them are less than 20, similarly 90 has neighbors 23 and 67.
#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void maxThanNeighbour(int arr[], int size)
{
    int newArr[size];
    int max = arr[0];
    int k = 0;
    for (int i = 0; i < size - 1;)
    {
        if (i==0)
        {
            if (arr[0] > arr[1])
            {
                newArr[k] = arr[0];
                k++;
                i++;
                cout<<newArr[k];
            }
        }
        else if (i==size - 1)
        {
            if (arr[size - 1] > arr[size - 2])
            {
                newArr[k] = arr[size - 1];
                k++;
                i++;
            }
        }
        else if (arr[i] >= arr[i + 1] && arr[i] >= arr[i - 1])
        {
            newArr[k] = arr[i];
            k++;
            i++;
            cout<<newArr[k]<<endl;
        }
    }
    print(newArr,k);
}
int main()
{
    int arr[] = {3, 2, 7, 6, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    print(arr, arr_size);
    cout<<"New list started"<<endl;
    maxThanNeighbour(arr,arr_size);
    
    return 0;
}