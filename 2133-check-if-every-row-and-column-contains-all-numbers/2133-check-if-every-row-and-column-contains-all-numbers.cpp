class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++)
        {
            unordered_set<int> st;
            for(int j=0; j<n; j++)
            {
                if(st.count(matrix[i][j]))
                return false;

                st.insert(matrix[i][j]);
            }
        }

        for(int i=0; i<n; i++)
        {
            unordered_set<int> st;
            for(int j=0; j<n; j++)
            {
                if(st.count(matrix[j][i]))
                return false;

                st.insert(matrix[j][i]);
            }
        }


        return true;
    }
};