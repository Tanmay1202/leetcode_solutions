class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));

        for(int i=0; i<m; i++)
        {
            int sum = 0;
            for(int j=0; j<n; j++)
            {
                if(matrix[j][i] == 0)
                sum = 0;
                else
                sum += 1;

                dist[j][i] = sum;
            }
        }


        for(int i=0; i<n; i++)
        {
            sort(dist[i].rbegin(), dist[i].rend());
        }

        int ans = INT_MIN;

        for(int i=0; i<n; i++)
        {
            int inter = INT_MIN;
            for(int j=0; j<m; j++)
            {
                inter = max(inter, dist[i][j]*(j+1));
            }
            ans = max(ans, inter);
        }

        return ans;
    }

};