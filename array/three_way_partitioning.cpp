#include <iostream>
using namespace std;

// void threeWayPartitioning(int arr[], int size, int lower, int higher)
// {
//     int start = 0, end = size - 1;

//     for (int i = 0; i <= end;) {
//         if (arr[i] < lower) {
//             if (i == start) {
//                 start++;
//                 i++;
//             }
//             else
//                 swap(arr[i++], arr[start++]);
//         }
//         else if (arr[i] > higher)
//             swap(arr[i], arr[end--]);
//         else
//             i++;
//     }

//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
void threewaypartitioning(int arr[], int n, int l, int h)
{
    int begin = 0, end = n - 1;
    for (int i = 0; i <= end; i++)
    {
        if (arr[i] < l)
        {
            swap(arr[i], arr[begin]);
            begin++;
        }
        else if (arr[i] > h)
        {
            swap(arr[i], arr[end]);
            i--;
            end--;
        }
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int arr[] = {3, 1, 2, 5, 8, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    threewaypartitioning(arr, size, 2, 4);
    return 0;
}
