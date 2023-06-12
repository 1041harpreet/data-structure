#include <iostream>
using namespace std;
void spiralPrint(int arr[][4], int row, int col)
{
    int startingRow = 0;
    int endingRow = row - 1;
    int startingCol = 0;
    int endingCol = col - 1;
    int count = 0;
    int total = row * col;
    while (count < total)
    {
        //starting row
        for (int cols = startingCol; cols <= endingCol; cols++)
        {
            cout << arr[startingRow][cols] << " ";
            count++;
        }
        startingRow++;

        for (int rows = startingRow; rows <= endingRow; rows++)
        {
            cout << arr[rows][endingCol] << " ";
            count++;
        }
        endingCol--;
        for (int cols = endingCol; cols >= startingCol; cols--)
        {
            cout << arr[endingRow][cols] << " ";
            count++;
        }
        endingRow--;
        for (int rows = endingRow; rows >= startingRow; rows--)
        {
            cout << arr[rows][startingCol] << " ";
            count++;
        }
        startingCol++;
    }
}
int main()
{
    int arr[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
       
    };
    spiralPrint(arr,3,4);
    return 0;
}