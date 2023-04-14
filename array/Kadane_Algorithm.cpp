// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum
// print max sum that can be obtained from set of sub array
#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int maxSum(int arr[], int size)
{
    int max_sum = INT_MIN;
    int cur_sum=0;
    for (int i = 0; i < size - 1; i++)
    {
        cur_sum += arr[i];
        if(cur_sum >max_sum){
            max_sum=cur_sum;
        }
        if (cur_sum <0)
        {
            cur_sum=0;
        }
        
       
    }
    return max_sum;
}
int main()
{
    int arr[] = {3, 2, -4, 9, -5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    print(arr, arr_size);
    cout<<"Max sum is : "<<maxSum(arr, arr_size);
    return 0;
}