#include <iostream>
using namespace std;
// int smallestSubarrayGreaterSum(int arr[], int size, int sum)
// {
//     int min_length = size + 1;
//     for (int i = 0; i < size; i++)
//     {
//         int min_sum = arr[i];
//         if (min_sum > sum)
//         {
//             return 1;
//         }
//         for (int j = i + 1; j < size; j++)
//         {
//             min_sum = min_sum + arr[j];
//             if (min_sum > sum && min_length > (j - i + 1))
//             {
//                 min_length = j - i + 1;
//             }
//         }
//     }
//     return min_length;
// }
int smallestSubarrayGreaterSum(int arr[], int size, int sum){
    int min_length = size + 1;
    
}
int main()
{
    int arr[]={1,2,5,1,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum=35;
    cout << smallestSubarrayGreaterSum(arr, size, sum);
    return 0;
}