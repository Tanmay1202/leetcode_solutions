class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n);
        queue<pair<int, int>> q;
        int count = 0;
        int fresh = 0;

        for (int i = 0; i < n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                if(grid[i][j] == 2) 
                q.push({i, j});
                else if(grid[i][j] == 1)
                fresh++;
            }
        }

        if(fresh == 0) return 0;

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                pair<int, int> front = q.front();
                q.pop();

                int x = front.first;
                int y = front.second;

                for(int i=0; i<4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx>=0 && ny>=0 && nx<n && ny<m)
                    {
                        
                        if(grid[nx][ny] == 1)
                        {
                            fresh--;
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            if(!q.empty()) count++;
        }

        if(fresh == 0) return count;

        return -1;
    }
};