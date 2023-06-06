#include <iostream>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void mergeTwoSortedArray(int arr[], int arr1[], int n, int m)
{
    int i = 0,  j = 0;
    
   
    while (i < n && j < m)
    {
        if (arr1[j] >= arr[i])
        {
            i++;
        }
        else if (arr1[j] < arr[i])
        {
            swap(arr1[j], arr[i]);
            i++;
        }
        cout<< "i value is "<<i<<" j value "<<j<<endl;
        if(arr1[j+1]<arr1[j]&& j<m-1){
            int temp=arr1[j];
            int t=j+1;
            while (arr1[j+1]<temp&& t<m)
            {
                arr1[t-1]=arr1[t];
                t++;
            }
            arr1[t-1]=temp;
            
        }
    }
    print(arr,n);
    print(arr1,m);
}
int main()
{
    int arr1[] = {2,2,5,8};
    int arr2[] = {1,2,5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    mergeTwoSortedArray(arr1, arr2, n, m);
    return 0;
}