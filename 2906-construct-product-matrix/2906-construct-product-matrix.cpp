class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> prefix(n, vector<long long>(m, 1));
        vector<vector<long long>> suffix(n, vector<long long>(m, 1));

        long long prevProd = 1;
        long long prevNum = grid[0][0];

        long long suffProd = 1;
        long long suffNum = grid[n-1][m-1];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }

                prefix[i][j] = (prevProd * prevNum) % 12345;

                prevProd = prefix[i][j];
                prevNum = grid[i][j];
            }
        }


        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(i == n-1 && j == m-1)
                {
                    continue;
                }

                suffix[i][j] = (suffProd * suffNum) % 12345;

                suffProd = suffix[i][j];
                suffNum = grid[i][j];
            }
        }


        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                grid[i][j] = (prefix[i][j] * suffix[i][j]) % 12345;
                // grid[i][j] %= 12345;
            }
        }


        return grid;

    }
};