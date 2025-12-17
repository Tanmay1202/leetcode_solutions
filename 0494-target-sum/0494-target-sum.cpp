class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((target + sum)%2 != 0 || sum < abs(target))
        return 0;

        int S1 = (target + sum)/2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(S1 + 1, 0));

        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=S1; j++)
            {
                if(j < nums[i-1])
                dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][S1];


    }
};