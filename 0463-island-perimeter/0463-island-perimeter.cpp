class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 1;
        if(visited[i][j])
            return 0;

        visited[i][j] = true;

        int perimeter = 0;
        perimeter += dfs(grid, i-1, j, n, m, visited); // up
        perimeter += dfs(grid, i+1, j, n, m, visited); // down
        perimeter += dfs(grid, i, j-1, n, m, visited); // left
        perimeter += dfs(grid, i, j+1, n, m, visited); // right

        return perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    return dfs(grid, i, j, n, m, visited);
                }
            }
        }

        return 0;
    }
};
