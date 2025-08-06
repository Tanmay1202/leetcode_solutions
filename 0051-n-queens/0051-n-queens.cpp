class Solution {
private:
    void solve(int n, int row, vector<vector<string>> &result, vector<string>& board, unordered_set<int>& columns, unordered_set<int>& diag1, unordered_set<int>& diag2)
    {
        if(row == n)
        {
            result.push_back(board);
            return;
        }


        for(int col = 0; col<n; col++)
        {
            if(columns.count(col) || diag1.count(row - col) || diag2.count(row + col))
            continue;


            board[row][col] = 'Q';
            columns.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            solve(n, row + 1, result, board, columns, diag1, diag2);

            board[row][col] = '.';
            columns.erase(col);
            diag1.erase(row-col);
            diag2.erase(row + col);

        }
    }
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> columns;
        unordered_set<int> diag1; // row - col
        unordered_set<int> diag2; // row + col


        solve(n, 0, result, board, columns, diag1, diag2);

        return result;
    }
};