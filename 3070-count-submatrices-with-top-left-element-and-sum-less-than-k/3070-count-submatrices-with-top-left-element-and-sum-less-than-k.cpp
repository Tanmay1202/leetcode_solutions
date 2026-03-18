class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> rowSum(n, vector<int>(m, 0));
        vector<vector<int>> colSum(n, vector<int>(m, 0));
        vector<vector<int>> subMatSum(n, vector<int>(m, 0));

        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                rowSum[i][j] = grid[i][j];
                if(j > 0)
                    rowSum[i][j] += rowSum[i][j-1];
            }
        }

        
        for(int j = 0; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                colSum[i][j] = grid[i][j];
                if(i > 0)
                    colSum[i][j] += colSum[i-1][j];
            }
        }

        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                subMatSum[i][j] = rowSum[i][j] + colSum[i][j] - grid[i][j];

                if(i > 0 && j > 0)
                    subMatSum[i][j] += subMatSum[i-1][j-1];
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(subMatSum[i][j] <= k)
                    count++;
            }
        }

        return count;
    }
};