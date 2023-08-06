#include <iostream>
#include <unordered_map>
using namespace std;
void reverseArray(int *arr, int n,int m)
{
    if (m >= n)
        return;
    int i = m;
    int j = n - 1;
    while (i < j) {
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Reversing: ";
    print(arr, arr_size);
    reverseArray(arr, arr_size,3);
    cout << endl
         << "After Reverseing :";
    print(arr, arr_size);
    return 0;
}

// using vector methods
// void reverseArray(vector<int> &arr, int m)
// {
//     int n = arr.size();
//     // Reverse the entire array
//     reverse(arr.begin(), arr.end());

//     // Reverse the first (n-m) elements
//     reverse(arr.begin(), arr.begin() + n - m);

//     // Reverse the last m elements
//     reverse(arr.begin() + n - m, arr.end());
// }