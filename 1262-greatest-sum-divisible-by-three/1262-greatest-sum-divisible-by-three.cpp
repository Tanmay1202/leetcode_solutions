class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for(int i=0; i<nums.size(); i++)
        {
            vector<int> old = dp;
            int x = nums[i];
            for(int j=0; j<dp.size(); j++)
            {
                int candidate = old[j] + x;
                int new_r = candidate%3;
                dp[new_r] = max(dp[new_r], candidate);
            }
        }

        return dp[0];
    }
};