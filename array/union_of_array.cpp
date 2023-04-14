#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int findCommon(int arr[], int size, int arr2[], int size2)
{
    int common = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr[i] == arr2[j])
            {
                common++;
            }
        }
    }
    return common;
}
void intersectionOfArray(int arr[],int size,int arr2[],int size2,int common) {
    int intersectArray[common];
    int k=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if(arr[i]==arr2[j]){
                intersectArray[k]=arr[i];
                k++;
            }
        }
    }
    print(intersectArray,common);
    

}
void unionOfArray(int arr[], int size, int arr2[], int size2, int common)
{
    int i = 0;
    int j = 0;
    int k = 0;
    // int common = 0;
    int size3 = size + size2 - common;
    int arr3[size3];

    for (i = 0; i < size; i++)
    {
        arr3[k] = arr[i];
        k++;
    }

    for (j = 0; j < size2; j++)
    {
        int flag = 1;
        for (int i = 0; i < size; i++)
        {
            if (arr2[j] == arr[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            arr3[k] = arr2[j];
            k++;
        }
    }

    cout << "\nUnion of two arrays is:\n";
    for (i = 0; i < size3; ++i)
    {
        cout << arr3[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 16, 4, 5};
    int arr2[] = {11, 12, 16,4 };
    int common;
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int arr_size2 = sizeof(arr2) / sizeof(arr2[0]);
    common = findCommon(arr, arr_size, arr2, arr_size2);
    // print(arr, arr_size);
    // unionOfArray(arr, arr_size, arr2, arr_size2, common);
    intersectionOfArray(arr, arr_size, arr2, arr_size2, common);

    return 0;
}