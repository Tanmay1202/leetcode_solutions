class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, -1));

        for (auto& it : edges) {
            int i = it[0];
            int j = it[1];
            int val = it[2];

            matrix[i][j] = val;
            matrix[j][i] = val;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] == -1 || matrix[k][j] == -1)
                        continue;

                    if (matrix[i][j] == -1) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    } else {
                        matrix[i][j] =
                            min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        int ans = -1;
        int minCount = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(i!=j && matrix[i][j] != -1 && matrix[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }

            if(count <= minCount)
            {
                minCount = count;
                ans = i;
            }
        }


        return ans;
    }
};