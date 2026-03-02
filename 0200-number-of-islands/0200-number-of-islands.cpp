class Solution {
private:
    void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
    {
        if(i > n-1 || j > m-1 || i < 0 || j < 0 || grid[i][j] != '1')
        return;

        //visited[i][j] = true;
        grid[i][j] = '0';

        dfs(grid, i+1, j, n, m);
        dfs(grid, i-1, j, n, m);
        dfs(grid, i, j+1, n, m);
        dfs(grid, i, j-1, n, m);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        //vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    dfs( grid, i, j, n, m);
                }
            }
        }


        return count;
    }
};