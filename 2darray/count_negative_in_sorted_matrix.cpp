#include <iostream>
using namespace std;
//sieve method
int countNegative(int arr[][4], int row, int col)
{
    int count = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(arr[i][j] < 0){
                count++;
            }
        }

    }
    return count;
}
int main(int argc, char const *argv[])
{
    int arr[4][4] = {
        {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
        cout << countNegative(arr, 4, 4);
    return 0;
}
