#include<iostream>
using namespace std;
void printFirstNegativeInteger(int arr[], int k, int n)
{
    int firstNegativeIndex = 0;
    int firstNegativeElement;
 
    for (int i = k - 1; i < n; i++) {
        // skip out of window and positive elements
        while ((firstNegativeIndex < i)
               && (firstNegativeIndex <= i - k
                   || arr[firstNegativeIndex] >= 0)) {
            firstNegativeIndex++;
        }
 
        // check if a negative element is found, otherwise
        // use 0
        if (arr[firstNegativeIndex] < 0) {
            firstNegativeElement = arr[firstNegativeIndex];
            
        }
        else {
            firstNegativeElement = 0;
        }
        cout << firstNegativeElement << " ";
    }
}
int main(){
    int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, k, n);
    return 0;
}