class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int id, int n, int m)
    {
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid[i][j] != 1)
        return 0;

        grid[i][j] = id;

        return 1 + dfs(i+1, j, grid, id, n, m) + dfs(i, j+1, grid, id, n, m) + dfs(i-1, j, grid, id, n, m) + dfs(i, j-1, grid, id, n, m);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int id = 2;
        unordered_map<int, int> area;

        int ans = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    area[id] = dfs(i,j, grid, id, n, m);
                    ans = max(ans, area[id]);

                    id++;
                }
            }
        }



        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 0)
                {
                    unordered_set<int> seen;
                    int curr = 1;

                    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

                    for(auto [dx, dy]: dirs)
                    {
                        int nx = dx + i;
                        int ny = dy + j;

                        if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] > 1)
                        seen.insert(grid[nx][ny]);
                    }


                    for(auto &it: seen)
                    {
                        curr += area[it];
                    }


                    ans = max(ans, curr);
                }
            }
        }


        return ans;



    }
};