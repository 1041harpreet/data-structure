#include <iostream>
using namespace std;
void sorting(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[10] = {19, 36, 45, 20, 55, 45, 89, 15, 23, 05};
    cout << "Initialize" << endl;
    // sorting(arr, 10);
    cout << "array after sorting" << endl;
 

    for (int i = 1; i < 10; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
     for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}