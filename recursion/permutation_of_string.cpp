#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void solution(vector<vector<int>>& ans, int index , vector<int> nums){
        if(index >=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i =index; i<nums.size();i++){
            swap(nums[index],nums[i]);
            solution(ans,index+1,nums);
            swap(nums[index],nums[i]);
        }
      
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

       
        int index=0;
        solution(ans,index,nums);
        return ans;
    }
};