class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 1000000007;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        int t0 = grid[0][0] % k;
        dp[0][0][t0] = 1;

        for(int i=1; i<n; i++){
            int t = grid[i][0] % k;
            for(int r=0; r<k; r++){
                int shifted = (r + t) % k;
                dp[i][0][shifted] = (dp[i][0][shifted] + dp[i-1][0][r]) % MOD;
            }
        }

        for(int j=1; j<m; j++){
            int t = grid[0][j] % k;
            for(int r=0; r<k; r++){
                int shifted = (r + t) % k;
                dp[0][j][shifted] = (dp[0][j][shifted] + dp[0][j-1][r]) % MOD;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                int t = grid[i][j] % k;
                for(int r=0; r<k; r++){
                    int shifted = (r + t) % k;
                    dp[i][j][shifted] = (
                        (long long)dp[i][j][shifted]
                        + dp[i-1][j][r]
                        + dp[i][j-1][r]
                    ) % MOD;
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};
