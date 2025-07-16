class Solution {
private:
    void backtrack(vector<int>& nums, int target, int &count, int sum, int i)
    {
        if(i == nums.size())
        {
            if(target == sum)
            count++;

            return;
        }

        backtrack(nums, target, count, sum+nums[i], i+1);
        backtrack(nums, target, count, sum-nums[i], i+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int count = 0;
        
        backtrack(nums, target, count, 0, 0);

        return count;
    }
};