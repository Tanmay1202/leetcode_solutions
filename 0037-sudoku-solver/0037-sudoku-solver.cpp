class Solution {
public:
    bool validValue(vector<vector<char>> &board, int r, int c, char ch)
    {
        for(int i=0; i<9; i++)
        {
            if(board[r][i] == ch) return false;
        }

        for(int j=0; j<9; j++)
        {
            if(board[j][c] == ch) return false;
        }

        int rowStart = (r/3)*3; int colStart = (c/3)*3;

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(board[i + rowStart][j + colStart] == ch) return false;
            }
        }

        return true;
    }
    bool backtrack(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                continue;

                for(int val=1; val<=9; val++)
                {
                    char ch = val + '0';
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
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};