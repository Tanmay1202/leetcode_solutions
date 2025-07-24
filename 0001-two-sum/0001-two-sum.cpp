class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int n = target - nums[i];
            if(mp.count(n))
            {
                return {mp[n], i};
            }

            mp[nums[i]] = i; 
        }

        return {-1, -1};
    }
};