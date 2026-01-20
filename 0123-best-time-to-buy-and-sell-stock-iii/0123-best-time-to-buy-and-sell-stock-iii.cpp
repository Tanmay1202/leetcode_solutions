class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        const int NEG_INF = -1e9;

        vector<vector<int>> prev(3, vector<int>(2, NEG_INF));
        vector<vector<int>> curr(3, vector<int>(2, NEG_INF));

        // day 0 initialization
        prev[0][0] = 0;
        prev[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            // reset curr
            for (int t = 0; t < 3; t++)
                for (int h = 0; h < 2; h++)
                    curr[t][h] = NEG_INF;

            // t = 0
            curr[0][0] = prev[0][0];
            curr[0][1] = max(prev[0][1], prev[0][0] - prices[i]);

            // t = 1
            curr[1][0] = max(prev[1][0], prev[0][1] + prices[i]);
            curr[1][1] = max(prev[1][1], prev[1][0] - prices[i]);

            // t = 2
            curr[2][0] = max(prev[2][0], prev[1][1] + prices[i]);
            // curr[2][1] is illegal, never touched

            prev = curr;
        }

        return max({prev[0][0], prev[1][0], prev[2][0]});
    }
};
