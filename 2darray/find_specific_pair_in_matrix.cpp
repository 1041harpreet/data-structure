// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b)
// over all choices of indexes such that both c > a and d > b.

#include <iostream>
using namespace std;
int maxValue(int arr[5][5], int row, int col)
{
    int i = 0;
    int j = 0;
    int max = INT_MIN;
    for (int a = 1; a < row - 1; a++)
    {
        for (int b = 1; b < col - 1; b++)
        {
            for (int c = 0; c < row; c++)
            {
                for (int d = 0; d < col; d++)
                {
                    if (max < (arr[c][d] - arr[a][b]))
                    {
                        max = arr[c][d] - arr[a][b];
                    }
                }
            }
        }
    }
    return max;
}
int main()
{
    int mat[5][5] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout<<maxValue(mat,5,5);
    return 0;
}