// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.
// 1 using map
#include <iostream>
#include <unordered_map>
using namespace std;
void findRepeatNumber(int arr[], int size)
{
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
        map[arr[i]]++;
    }
    for (auto i : map)
    {
        if (i.second > 1)
        {
            cout<< i.first;
        }
    }

}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    findRepeatNumber(arr, arr_size);
    return 0;
}