// given array has all positive vales and need to merge operation so that it becomes a palindrome
#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int palindrome(int arr[], int size)
{
    int mergeop = 0;
    for (int i = 0, j = size - 1; i <=j;)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if (arr[i] > arr[j]){
            j--;
            arr[j]=arr[j]+arr[j+1];
            mergeop++;
        }
        else{
             i++;
            arr[i]=arr[i]+arr[i-1];
            mergeop++;
        }
    }
    
    return mergeop;
}

int main()
{
    int arr[] = {3, 2, 1, 6, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout<<"no of merge op required "<<palindrome(arr, arr_size);
    return 0;
}