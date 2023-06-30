#include <iostream>
using namespace std;
// void swap(int arr[], int pos1, int pos2)
// {
//     int temp;
//     temp = arr[pos1];
//     arr[pos1] = arr[pos2];
//     arr[pos2] = temp;
// }
// int partition(int* arr, int low ,int high ,int pivot){
//     int i = low;
// 	int j = low;
// 	while (i <= high)
// 	{
// 		if (arr[i] > pivot)
// 		{
// 			i++;
// 		}
// 		else
// 		{
// 			swap(arr, i, j);
// 			i++;
// 			j++;
// 		}
// 	}
// 	return j - 1;

// }
// void quickSort(int *arr, int start, int end)
// {
//     if (start < end)
//     {
//         int pivot=arr[end];
//         //partitioning the array around a particular element.
//         int index=partition(arr,start,end,pivot);
//         quickSort(arr, start, index-1);
//         quickSort(arr,index+1,end);
//     }
// }

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int s = start;
    int e = end;
    int count = 0;
    for (int i = start+1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int index = start + count;
    swap(arr[start], arr[index]);
    while (s < index && e > index)
    {
        while (arr[s] < pivot)
        {
            ++s;
        }
        while (arr[e] > pivot)
        {
            --e;
        }
        if (s < index && e > index)
        {
            swap(arr[s++], arr[e--]);
        }
    }
    return index;
}
void quickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p+1, end);
}
int main()
{
    int arr[] = {3, 5, 12, 0, 4};
    quickSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}