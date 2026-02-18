class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;

            int steps = it.second;

            dist[x][y] = steps;

            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >=0 && nx < n && ny < m && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }


        return dist;

    }
};