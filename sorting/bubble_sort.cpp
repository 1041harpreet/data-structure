
#include<iostream>
using namespace std;
void swap( int* pos1, int* pos2){
	int temp;
	temp =*pos1;
	*pos1 = *pos2;
	*pos2 = temp;
}

void bubblesort(int size,int arr[]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; i < size-1; i++)
        {
               for (j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
                }
            
        }
        
    }
    
}

int main()
{
	int n ;
	cout << " enter the size of array";
	cin>>n;
	int arr[n];
	for( int i = 0 ; i < n; i++){
		cin>> arr[i];
	}
    bubblesort(n,arr);
	cout<<"The sorted array is: ";
	for( int i = 0 ; i < n; i++){
		cout<< arr[i]<<"\t";
	}
    return 0;
}
