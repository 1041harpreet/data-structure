#include <iostream>
using namespace std;
void mergeTwoSortedArray(int arr[], int arr1[], int n, int m)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int arr2[n + m];
    if(n==0){
        for(j=0;j<m;j++){
            arr2[k]=arr1[j];
            k++;
        }
    }
    if(m==0){
        for(i=0;i<n;i++){
            arr2[k]=arr[i];
            k++;
        }
    }
    while (i < n && j < m)
    {
        if (arr[i] > arr1[j])
        {
            arr2[k] = arr1[j];
            j++;
            k++;
        }
        else
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
    }
    while (i < n)
    {
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr2[k] = arr1[j];
        j++;
        k++;
    }
    for (int i = 0; i < n + m; i++)
    {
        cout << arr2[i] << " ";
    }
}
int main()
{
    int arr1[] = {};
    int arr2[] = {2};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    mergeTwoSortedArray(arr1, arr2, n, m);
    return 0;
}