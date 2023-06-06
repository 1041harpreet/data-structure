#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findDuplicate(vector<int>& nums) {
         unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    for (auto i : map)
    {
        // cout<<i.first<<" "<<i.second<<endl;
        if (i.second > 1)
        {
            return i.first;
        }
    }
    return 0;
    }
    int main(){
        vector<int> nums = {1,2,3,2,5,6};
        int ans = findDuplicate(nums);
        cout<<ans;
        return 0;
    }