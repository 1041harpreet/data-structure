#include <iostream>
using namespace std;
void conquer(int arr[], int mid, int start, int end)
{
    int newarr[end - start + 1];
    int ind1 = start;
    int ind2 = mid + 1;
    int x = 0;
    while (ind1 <= mid && ind2 <= mid)
    {
        if (arr[ind1] <= arr[ind2])
        {
            newarr[x] = arr[ind1];
            x++;
            arr[ind1]++;
        }
        else
        {

            newarr[x] = arr[ind2];
            x++;
            arr[ind2]++;
        }
    }
    while (ind1 <= mid)
    {
        newarr[x] = arr[ind1];
        x++;
        arr[ind1]++;
    }
    while (ind2 <= end)
    {
        newarr[x] = arr[ind2];
        x++;
        arr[ind2]++;
    }
    for (int i = 0; i < end - start + 1; i++)
    {
       for (int j = 0; i < end-start+1; j++)
       {
       arr[j]=newarr[i];
       }
       
    }
    
}
void mergeSort(int ar[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    // cout<<mid;
    mergeSort(ar, start, mid);
    mergeSort(ar, mid + 1, end);
    conquer(ar, mid, start, end);
}
int main()
{
    int ar[] = {12, 4, 23, 3, 19, 14, 8, 11};
    int n = sizeof(ar) / sizeof(ar[0]);
    mergeSort(ar, 0, n);
    cout<<"Aftr sort";
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<ar[i]<<" ";
        /* code */
    }
    
    return 0;
}