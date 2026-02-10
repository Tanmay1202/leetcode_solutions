class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;

        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];
        if (original == color) return image;

        q.push({sr, sc});
        image[sr][sc] = color;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty())
        {
            int sz = q.size();

            for(int i=0; i<sz; i++)
            {
                pair<int, int> front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;

                for(int i=0; i<4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == original)
                    {
                        q.push({nx, ny});
                        image[nx][ny] = color;
                    }
                }
            }
        }


        return image;
    }
};