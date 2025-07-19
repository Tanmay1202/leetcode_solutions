class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0;

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        if(fresh == 0)
            return 0;

        int min = 0;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                pair<int, int> node = q.front();
                q.pop();

                int row = node.first;
                int col = node.second;

                for(int j = 0; j < 4; j++)
                {
                    int x = row + dx[j];
                    int y = col + dy[j];

                    if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
                    {
                        q.push({x, y});
                        grid[x][y] = 2;
                        fresh--;
                    }
                }
            }

            if(!q.empty())
                min++;
        }

        if(fresh == 0)
            return min;
        
        return -1;
    }
};
