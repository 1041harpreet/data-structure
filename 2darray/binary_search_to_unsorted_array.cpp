#include <iostream>
using namespace std;
bool searchArray(int arr[][5], int row, int col, int target)
{
    int i = 0, j = col - 1;
    while (i < row && j >= 0)
    {
        int element = arr[i][j];
        cout << "element now at " << i << " " << j << " " << element << endl;
        if (element == target)
        {
            return 1;
        }
        if (element > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}
int main()
{
    int arr[5][5] = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    cout << searchArray(arr, 5, 5, 18);
    return 0;
}