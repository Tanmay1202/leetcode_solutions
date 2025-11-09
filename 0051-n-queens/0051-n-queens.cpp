class Solution {
private:
    void backtrack(vector<vector<string>> &result, vector<string> &board, unordered_set<int> column,unordered_set<int> diag1, unordered_set<int> diag2, int row, int n)
    {
        if(row == n)
        {
            result.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++)
        {
            if(column.count(col) || diag1.count(row+col) || diag2.count(row - col))
            continue;

            board[row][col] = 'Q';
            column.insert(col);
            diag1.insert(row+col);
            diag2.insert(row-col);

            backtrack(result, board, column, diag1, diag2, row + 1, n);

            board[row][col] = '.';
            column.erase(col);
            diag1.erase(row + col);
            diag2.erase(row - col);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        unordered_set<int> col;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        backtrack(result, board, col, diag1, diag2, 0, n);

        return result;
    }
};