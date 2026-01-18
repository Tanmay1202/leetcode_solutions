class Solution {
private:
    int n, m;

    int isMagic(
        int r,
        int c,
        vector<vector<int>>& rowPrefix,
        vector<vector<int>>& colPrefix,
        vector<vector<int>>& grid
    ) {
        int best = 1;
        int maxK = min(n - r, m - c);

        for (int k = 2; k <= maxK; k++) {

            // target sum (first row)
            int target =
                rowPrefix[r][c + k - 1]
                - (c > 0 ? rowPrefix[r][c - 1] : 0);

            bool ok = true;

            // check rows
            for (int i = r; i < r + k; i++) {
                int rowSum =
                    rowPrefix[i][c + k - 1]
                    - (c > 0 ? rowPrefix[i][c - 1] : 0);
                if (rowSum != target) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            // check columns
            for (int j = c; j < c + k; j++) {
                int colSum =
                    colPrefix[r + k - 1][j]
                    - (r > 0 ? colPrefix[r - 1][j] : 0);
                if (colSum != target) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            // main diagonal
            int diag1 = 0;
            for (int d = 0; d < k; d++)
                diag1 += grid[r + d][c + d];
            if (diag1 != target) continue;

            // anti-diagonal
            int diag2 = 0;
            for (int d = 0; d < k; d++)
                diag2 += grid[r + d][c + k - 1 - d];
            if (diag2 != target) continue;

            best = k;
        }

        return best;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> rowPrefix(n, vector<int>(m, 0));
        vector<vector<int>> colPrefix(n, vector<int>(m, 0));

        // row prefix
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
                rowPrefix[i][j] = sum;
            }
        }

        // column prefix
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += grid[i][j];
                colPrefix[i][j] = sum;
            }
        }

        int ans = 1;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                ans = max(ans, isMagic(r, c, rowPrefix, colPrefix, grid));
            }
        }

        return ans;
    }
};
