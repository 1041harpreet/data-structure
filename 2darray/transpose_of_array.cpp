#include<iostream>
using namespace std;
void transposeMatrix(int arr[][3],int row , int col){
    for (int rows = 0; rows < row; rows++)
    {
        for (int cols = rows+1; cols < col; cols++){
            swap(arr[rows][cols],arr[cols][rows]);
        }
    }
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
        cout<<arr[i][j]<<" ";
      }
      
   }
    
}

int main()
{
    int arr[3][3]={
        {1,2,3},
        {5,6,7},
        {9,10,11} 
    };
    transposeMatrix(arr,3,3);
    /* code */
    return 0;
}
