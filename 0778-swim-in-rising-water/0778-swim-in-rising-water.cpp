class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while(!pq.empty())
        {
            auto [t, x, y] = pq.top(); pq.pop();

            if(x == n-1 && y == n-1)
            return t;

            for(auto &it: dirs)
            {
                int nx = it[0] + x;
                int ny = it[1] + y;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny])
                {
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        return -1;
    }
};