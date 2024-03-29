// Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
// Example:
// Input:
// mat[4][5] = {{1, 2, 1, 4, 8},
//              {3, 7, 8, 5, 1},
//              {8, 7, 7, 3, 1},
//              {8, 1, 2, 7, 9},
//             };
// Output:
// 1 8 or 8 1
// 8 and 1 are present in all rows.
#include <iostream>
#include <unordered_map>
using namespace std;
void commonElements(int arr[4][5], int m, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[(arr[0][i])] = 1;
    }
    // for (auto x : mp)
    // cout << x.first << " " <<
    //         x.second << endl;

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && mp[arr[i][j]] == i)
            {
                // increment the count of the element by 1
                mp[arr[i][j]] = i + 1;
 
                // if `i` represent the last row, print the element
                if (i == m - 1) {
                    cout << arr[i][j] << " ";
                }
            }
        }
    }
}
int main()
{
    int mat[4][5] = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
    commonElements(mat, 4, 5);
    return 0;
}