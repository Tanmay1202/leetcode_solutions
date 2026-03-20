class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int row = m-k+1;
        int col = n-k+1;

        vector<vector<int>> res(m-k+1, vector<int>(n-k+1, 0));

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                vector<int> inter;
                for (int r = 0; r < k; r++) 
                {
                    for (int c = 0; c < k; c++) 
                    {
                        inter.push_back(grid[i + r][j + c]);
                    }
                }

                sort(inter.begin(), inter.end());
                int minDiff = INT_MAX;

                for(int o=1; o<inter.size(); o++)
                {
                    if(inter[o] != inter[o-1])
                    minDiff = min(minDiff, abs(inter[o] - inter[o-1]));
                }


                minDiff = (minDiff == INT_MAX ? 0 : minDiff);

                res[i][j] = minDiff;
            }
        }

        return res;

    }
};