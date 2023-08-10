// 1 simple for loop
// void rotate(int arr[], int n)
// {
//     int last=arr[n-1];
//     for(int i=n-2;i>=0;i--){
//         arr[i+1]=arr[i];
//     }
//     arr[0]=last;
// }
//TC : O(n) and space O(1)

// We can use two pointers, As we know in cyclic rotation we will bring last element to first and shift rest in forward direction, 
// we can do this by swapping every element with last element till we get to the last point.

