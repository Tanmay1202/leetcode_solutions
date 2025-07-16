class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int target = accumulate(nums.begin(), nums.end(), 0);

        if(target%2 != 0)
        return false;

        target = target/2;

        int n = nums.size();

        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(target+1, 0));

        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=target; j++)
            {
                if(j < nums[i-1])
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
            }
        }

        return dp[n][target];

        
    }
};