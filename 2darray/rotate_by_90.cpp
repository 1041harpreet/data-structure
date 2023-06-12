#include <iostream>
using namespace std;

void transposeMatrix(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = i + 1; j < row; j++)
            swap(arr[i][j], arr[j][i]);
}
void rotateBy(int arr[][4], int row, int col)
{
    transposeMatrix(arr, row, col);

    int mid = col / 2;
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < row; j++)
        {
            swap(arr[j][i], arr[j][col - i - 1]);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    // 1 [[7,4,1],[8,5,2],[9,6,3]]
    // 2 [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
}
int main()
{
    // int arr[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    int arr[4][4] = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotateBy(arr, 4, 4);
    return 0;
}