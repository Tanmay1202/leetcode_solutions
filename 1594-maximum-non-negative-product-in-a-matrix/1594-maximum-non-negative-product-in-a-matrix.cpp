class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int mod = 1e9 + 7;

        vector<vector<long long>> maxDp(n, vector<long long>(m));
        vector<vector<long long>> minDp(n, vector<long long>(m));

        minDp[0][0] = maxDp[0][0] = grid[0][0];

        for(int i=1; i<n; i++)
        {
            maxDp[i][0] = minDp[i][0] = maxDp[i-1][0]*grid[i][0];
        }

        for(int i=1; i<m; i++)
        {
            maxDp[0][i] = minDp[0][i] = maxDp[0][i-1]*grid[0][i];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                long long a = maxDp[i-1][j] * grid[i][j];
                long long b = minDp[i-1][j] * grid[i][j]; 
                long long c = maxDp[i][j-1] * grid[i][j]; 
                long long d = minDp[i][j-1] * grid[i][j]; 

                maxDp[i][j] = max({a, b, c, d});
                minDp[i][j] = min({a, b, c, d});
            }
        }


        if(maxDp[n-1][m-1] < 0) return -1;

        return maxDp[n-1][m-1]%mod;
    }
};