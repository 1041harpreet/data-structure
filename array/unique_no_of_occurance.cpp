// size=2m+1
//  if m=2 then array is 1 1 2 2 3 find unique like 3 in this case
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
bool checkUniqueOccurance(int arr[], int size)
{

    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
        map[arr[i]]++;
    }
    unordered_set<int> set;
    for (auto i : map)
    {
        if (set.count(i.second))
        {
            return false;
        }
        set.insert(i.second);
    }

    return true;
}
int main()
{
    int arr[] = {1, 2, 2, 2, 3, 3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    bool res = checkUniqueOccurance(arr, arr_size);
    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}