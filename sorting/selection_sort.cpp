
#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int arr[], int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{
		// arr= {14,35,66,36,1,45}
		min = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
			{
				min = j;
				swap(&arr[min], &arr[i]);
			}
	}
}

int main()
{
	int n;
	cout << " enter the size of array";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "selection sort start" << endl;
	selectionSort(arr, n);
	cout << "selection sort completed" << endl;
	cout << "The sorted array is: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	return 0;
}
