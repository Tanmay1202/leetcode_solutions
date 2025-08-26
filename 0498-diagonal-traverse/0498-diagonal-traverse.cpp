class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> result;
        result.reserve(n * m);

        int i = 0, j = 0;
        int dir = 1; // 1 = up-right, -1 = down-left

        while(result.size() < n * m)
        {
            result.push_back(mat[i][j]);

            int new_i = i + (dir == 1 ? -1 : 1);
            int new_j = j + (dir == 1 ? 1 : -1);

            if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
            {
                if(dir == 1) {
                    if(j + 1 < m) j++;
                    else i++;
                } else {
                    if(i + 1 < n) i++;
                    else j++;
                }
                dir = -dir;
            }
            else {
                i = new_i;
                j = new_j;
            }
        }

        return result;
    }
};
