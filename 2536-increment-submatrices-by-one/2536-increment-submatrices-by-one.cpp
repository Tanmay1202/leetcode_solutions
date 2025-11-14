class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int size = queries.size();
        

        for (int i = 0; i < size; i++) {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            

            for(int j=r1; j<=r2; j++)
            {
                res[j][c1] += 1;
                if(c2 + 1 < n)res[j][c2+1] -= 1;
            }
              
        } 


        for(int i=0; i<n; i++)
        {
            for(int j=1; j<n; j++)
            {
                res[i][j] = res[i][j] + res[i][j-1];
            }
        }

   

        return res;
    }           
};