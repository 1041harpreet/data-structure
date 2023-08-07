// 1 sort so all negative on left side
// 2 for loop and one j element to check last negative index and
//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print(int *arr, int n)
    {
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void negativeMove(int *arr, int n)
    {
        int i = 0;
        int j = n - 1;
        while (i <= j)
        {
             //1. if both are negative
             if (arr[i] < 0 && arr[j] < 0)
            {
                i++;
                
            }
             //2. if right is negative
           else if (arr[i] > 0 && arr[j] < 0)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
            //3. if both are positive
           else if (arr[i] > 0 && arr[j] > 0)
            {
                j--;
            }
            else{
              i++;  
              j--;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    Solution s;
    int arr[] = {1, -2, -3, -4, 5, -6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before moving : ";
    s.print(arr, arr_size);
    cout<<endl;
    cout << "after moving : " << endl;
    s.negativeMove(arr, arr_size);
    s.print(arr, arr_size);
    return 0;
}

// } Driver Code Ends