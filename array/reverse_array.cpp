#include <iostream>
using namespace std;
void print(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void reverse_arry(string arr[], int size)
{
    string new_arr[size];
    int j = size - 1;
    for (int i = 0; i < size ; i++, j--)
    {
        new_arr[i] = arr[j];
    }
    cout<<"new reverse array start here ..."<<endl;
    print(new_arr,size);
}
int main()
{
    string arr[] = {"1", "2", "3", "4", "5"};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    print(arr, arr_size);
    reverse_arry(arr, arr_size);
    return 0;
}