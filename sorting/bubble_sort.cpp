
#include<iostream>
using namespace std;


void bubblesort(int arr[],int size){
	for (int i = 0; i < size; i++)
	{
		bool swaped=false;
		for (int j = 0; j < size-i-1; j++)
		{
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swaped=true;
			}
		}
		if (swaped==false)
		{
			break;
		}
		
		
	}
	for (int i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	
}

int main()
{
	int arr[]={1,2,3,4,5};
    bubblesort(arr,5);
	
    return 0;
}
