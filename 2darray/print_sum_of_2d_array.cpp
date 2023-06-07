#include<iostream>
using namespace std;
void rowWiseSum(int arr[][4],int row,int col){
    int a[4];
    for (int i = 0; i < row; i++)
    {
        int sum=0;
        for (int j = 0; j < col; j++)
        {
            sum+=arr[i][j];
        }
        a[i]=sum;
        
    }
    for (int i = 0; i < 4; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
void columnWiseSum(int arr[][4],int row,int col){
    int a[4];
    for (int i = 0; i < col; i++)
    {
        int sum=0;
        for (int j = 0; j < row; j++)
        {
            sum+=arr[j][i];
        }
        a[i]=sum;
                
    }
    for (int i = 0; i < 4; i++)
    {
        cout<<a[i]<<" ";
    } 
    
}
int main(){
    int arr[4][4]={
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };
    // rowWiseSum(arr,4,4);
    columnWiseSum(arr,4,4);
    return 0;
}