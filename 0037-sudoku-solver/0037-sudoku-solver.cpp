class Solution {
private:
    bool validValue(vector<vector<char>>& board, int r, int c, char ch) 
    {
    
        for (int j = 0; j < 9; j++)
            if (board[r][j] == ch) return false;

        
        for (int i = 0; i < 9; i++)
            if (board[i][c] == ch) return false;

        
        int rowStart = (r/3)*3, colStart = (c/3)*3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[rowStart+i][colStart+j] == ch) return false;

        return true;
    }

    bool backtrack(vector<vector<char>>& board)
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] != '.')
                continue;

                for(int value=1; value<=9; value++)
                {
                    char ch = value + '0';

                    if(!validValue(board, i, j, ch))
                    continue;

                    board[i][j] = ch;
                    if(backtrack(board)) return true;
                    board[i][j] = '.';
                }

                return false;
            }
        }


        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        backtrack(board);
    }
};