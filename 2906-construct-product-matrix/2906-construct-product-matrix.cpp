class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        const int N = 12345;

        vector<vector<unsigned long long >> prefix(n, vector<unsigned long long >(m, 1));
        vector<vector<unsigned long long >> suffix(n, vector<unsigned long long >(m, 1));

        unsigned long long  prevProd = 1;
        unsigned long long  prevNum = grid[0][0];

        unsigned long long  suffProd = 1;
        unsigned long long  suffNum = grid[n-1][m-1];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }

                prefix[i][j] = (prevProd * prevNum) % N;

                prevProd = prefix[i][j];
                prevNum = grid[i][j];
            }
        }


        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(i == n-1 && j == m-1)
                {
                    continue;
                }

                suffix[i][j] = (suffProd * suffNum) % N;

                suffProd = suffix[i][j];
                suffNum = grid[i][j];
            }
        }


        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                grid[i][j] = (prefix[i][j] * suffix[i][j]) % N;
                // grid[i][j] %= N;
            }
        }


        return grid;

    }
};