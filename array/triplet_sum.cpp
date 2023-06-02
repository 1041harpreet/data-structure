#include<iostream>
using namespace std;
// using loops tc: O(n3)
// bool tripletSum(int arr[],int size, int sum){
//     for (int i = 0; i < size-2; i++)
//     {
//         for (int j = i+1; j < size-1; j++)
//         {
//             for (int k = j+1; k < size; k++)
//             {
//                 if(arr[i]+arr[j]+arr[k]==sum){
//                     cout<<"triplet "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
//                     return true;
//                 }
//             }
            
//         }
        
//     }
//     return false;
    
// }
bool tripletSum(int arr[],int size,int sum){
    int pt1=0;
    int pt2=size-1;
   while (pt1<pt2)
   {
       for (int i = 1; i < size-1; i++)
       {
        if(arr[pt1]+arr[pt2]+arr[i]==sum){
            cout<<"triplet "<<arr[pt1]<<" "<<arr[pt2]<<" "<<arr[i]<<endl;
            return true;
        }else{
            pt1++;
            pt2++;
        }
       }
       
   }
   
    return false;
}
int main(){
    int arr[]={1,2,3,4,1,2,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum=7;
    tripletSum(arr,size,sum);
    return 0;
}