class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> dp(numRows, vector<int>(numRows, 0));
        vector<vector<int>> result;

        int n = numRows;

        for(int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            vector<int> temp;
            temp.push_back(dp[i][0]); // push first 1

            for(int j = 1; j <= i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                temp.push_back(dp[i][j]);
            }

            result.push_back(temp);
        }

        return result;
    }
};
