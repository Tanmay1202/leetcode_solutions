class Solution {
private:
    void recurse(vector<vector<int>>& matrix, vector<int>& result, int top, int bottom, int left, int right)
    {
        if(top > bottom || left > right) return;

        // Traverse top row (left to right)
        for(int j = left; j <= right; j++)
            result.push_back(matrix[top][j]);

        // Traverse right column (top+1 to bottom)
        for(int i = top + 1; i <= bottom; i++)
            result.push_back(matrix[i][right]);

        // Traverse bottom row (right−1 to left), only if more than one row
        if(top < bottom)
        {
            for(int j = right - 1; j >= left; j--)
                result.push_back(matrix[bottom][j]);
        }

        // Traverse left column (bottom−1 to top+1), only if more than one column
        if(left < right)
        {
            for(int i = bottom - 1; i > top; i--)
                result.push_back(matrix[i][left]);
        }

        recurse(matrix, result, top + 1, bottom - 1, left + 1, right - 1);
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
        int n = matrix.size();
        int m = matrix[0].size();
        recurse(matrix, result, 0, n - 1, 0, m - 1);
        return result;
    }
};
