//Wix
/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.*/
/* Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>seen;
        for(int i=0; i<nums.size();i++)
        {
            int rem = target-nums[i];
            if(seen.count(rem))
                return {seen[rem],i};
            seen[nums[i]]=i;
        }
        return {-1,-1};
    }
};