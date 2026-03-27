class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] != 0) return -1;

        queue<pair<int, int>> q;

        q.push({0, 0});

        grid[0][0] = 1;
        int level = 0;

        while(!q.empty())
        {
            int sz = q.size();

            for(int i=0; i<sz; i++)
            {
                auto it = q.front();
                int x = it.first;
                int y = it.second;

                q.pop();

                if(x == n-1 && y == m-1)
                return level + 1;

                for(auto it: dirs)
                {
                    int nx = x + it[0];
                    int ny = y + it[1];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }

            }

            level++;
        }

        return -1;

    }
};