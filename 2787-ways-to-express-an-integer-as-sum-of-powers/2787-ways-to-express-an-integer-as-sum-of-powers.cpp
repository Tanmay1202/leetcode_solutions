class Solution {
public:
    int numberOfWays(int n, int x) 
    {
        int bases = floor(pow(n, 1.0/x));

        const int MOD = 1e9 + 7;
        
        vector<vector<int>> dp(bases + 1, vector<int>(n+1, 0));

        for(int i=0; i<=bases; i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1; i<=bases; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int wt = static_cast<int>(pow(i, x));
                if(j < wt)
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = (dp[i-1][j] + dp[i-1][j - wt]) % MOD;
            }
        }

        return dp[bases][n];
    }
};