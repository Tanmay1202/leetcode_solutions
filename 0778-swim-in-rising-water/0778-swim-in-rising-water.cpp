class Solution {
public:

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j, int t,int n)
    {
        if(i > n-1 || j > n-1 || i < 0 || j < 0 || visited[i][j] == true || grid[i][j] > t)
        return false;

        if(i == n-1 && j == n-1)
        return true;

        visited[i][j] = true;


        return dfs(grid, visited, i+1, j, t,n) ||
        dfs(grid, visited, i, j+1, t,n) ||
        dfs(grid, visited, i-1, j, t,n) ||
        dfs(grid, visited, i, j-1, t,n);
    }

    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int t=0; t<n*n; t++)
        {
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if(dfs(grid, visited, 0, 0, t, n))
            return t;
        }


        return -1;
    }
};