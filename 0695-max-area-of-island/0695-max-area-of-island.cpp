class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int &temp)
    {
        if(i == r || j == c || i < 0 || j < 0 || grid[i][j] == 0)
        return;

        grid[i][j] = 0;
        temp++;

        dfs(grid, i, j+1, r, c, temp);
        dfs(grid, i+1, j, r, c, temp);
        dfs(grid, i-1, j, r, c, temp);
        dfs(grid, i, j-1, r, c, temp);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();

        int ans = 0;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                int temp = 0;
                if(grid[i][j] == 1)
                {
                    dfs(grid, i, j, r, c, temp);
                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }
};