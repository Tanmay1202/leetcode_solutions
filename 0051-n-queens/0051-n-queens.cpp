class Solution {
public:
    void helper(unordered_set<int> &column, unordered_set<int> &diag1,
unordered_set<int> &diag2, vector<vector<string>> &res, vector<string> &board, int n, int row)
    {
        if(row == n)
        {
            res.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(diag2.count(row - col) || diag1.count(row + col) || column.count(col))
            continue;

            board[row][col] = 'Q';
            column.insert(col);
            diag1.insert(row + col);
            diag2.insert(row - col);

            helper(column, diag1, diag2, res, board, n, row + 1);

            board[row][col] = '.';
            column.erase(col);
            diag1.erase(row + col);
            diag2.erase(row - col);
        }
    }



    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> col;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));


        helper(col, diag1, diag2, res, board, n, 0);;

        return res;
    }
};