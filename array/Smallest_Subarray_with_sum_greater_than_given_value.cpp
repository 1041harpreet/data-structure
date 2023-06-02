#include <iostream>
using namespace std;
int smallestSubarray(int arr[], int size, int sum)
{
   
    int min_len=size+1;
    for (int i = 0; i < size; i++)
    {
        int count=arr[i];
        if(count >= sum){
            return 1;
        }
        for (int j = i+1; j < size; j++)
        {
            count=count+arr[j];
            if(count >= sum && min_len > (j-i+1)){
                min_len=j-i+1;
            }
        }
    }
    return min_len;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    cout << smallestSubarray(arr, size, sum);
    return 0;
}
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int size=nums.size();
//         int min_len=size+1;
//     for (int i = 0; i < size; i++)
//     {
//         int count=nums[i];
//         if(count >= target){
//             return 1;
//         }
//         for (int j = i+1; j < size; j++)
//         {
//             count=count+nums[j];
//             if(count >= target && min_len > (j-i+1)){
//                 min_len=j-i+1;
//             }
//         }
//     }
//     if(min_len > size){
//         return 0;
//     }
//     return min_len;
//     }
// };
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int size=nums.size();
//         int min_len=size+1;
//     for (int i = 0; i < size; i++)
//     {
//         int count=nums[size-i-1];
//         if(count >= target){
//             return 1;
//         }
//         for (int j = i+1; j < size; j++)
//         {
//             count=count+nums[size-j-1];
//             if(count >= target && min_len > (j-i+1)){
//                 min_len=j-i+1;
//             }
//         }
//     }
//     if(min_len > size){
//         return 0;
//     }
//     return min_len;
//     }
// };