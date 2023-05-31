#include <iostream>
#include <unordered_map>
using namespace std;
void findAllDuplicate(int arr[], int size)
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
            cout << i.first<<" ";
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8,8, 9, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    findAllDuplicate(arr, arr_size);
    return 0;
}