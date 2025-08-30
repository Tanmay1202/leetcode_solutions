class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row;
        unordered_set<char> col;

        // check rows
        for(int i = 0; i < board.size(); i++) {
            row.clear();
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') continue;
                if(row.count(board[i][j]))
                    return false;
                row.insert(board[i][j]);
            }
        }

        // check columns
        for(int i = 0; i < board[0].size(); i++) {
            col.clear();
            for(int j = 0; j < board.size(); j++) {
                if(board[j][i] == '.') continue;
                if(col.count(board[j][i]))
                    return false;
                col.insert(board[j][i]);
            }
        }

        unordered_set<char> boxes;

        for(int rowStart = 0; rowStart < board.size(); rowStart+=3)
        {
            for(int colStart = 0; colStart < board[0].size(); colStart+=3)
            {
                boxes.clear();

                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        if(board[rowStart + i][colStart + j] == '.')
                        continue;
                        else if(boxes.count(board[rowStart + i][colStart + j]))
                        return false;
                        boxes.insert(board[rowStart + i][colStart + j]);
                    }
                }
            }
        }

        return true; 
    }
};
