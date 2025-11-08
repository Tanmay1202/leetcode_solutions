class Solution {
private:
    void backtrack(vector<vector<char>>& board, string &word, vector<vector<bool>> &visited,
                   int i, int j, int idx, bool &flag)
    {
        if(flag) return;
        if(idx == word.size()) {
            flag = true;
            return;
        }

        int row = board.size(), col = board[0].size();
        if(i < 0 || j < 0 || i >= row || j >= col) return;
        if(visited[i][j] || board[i][j] != word[idx]) return;

        visited[i][j] = true;

        backtrack(board, word, visited, i + 1, j, idx + 1, flag);
        backtrack(board, word, visited, i - 1, j, idx + 1, flag);
        backtrack(board, word, visited, i, j + 1, idx + 1, flag);
        backtrack(board, word, visited, i, j - 1, idx + 1, flag);

        visited[i][j] = false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        bool flag = false;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word[0])
                    backtrack(board, word, visited, i, j, 0, flag);
                if(flag) return true;
            }
        }
        return flag;
    }
};
