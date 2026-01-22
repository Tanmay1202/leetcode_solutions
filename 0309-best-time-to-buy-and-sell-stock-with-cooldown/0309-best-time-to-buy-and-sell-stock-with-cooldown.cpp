class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        const int NEG_INF = -1e9;

        vector<int> prev(3, NEG_INF);
        vector<int> curr(3, NEG_INF);

        prev[0] = -prices[0];
        prev[2] = 0;

        for(int i=1; i<prices.size(); i++)
        {
            for(int j=0; j<3; j++)
            {
                curr[j] = NEG_INF;
            }

            curr[0] = max(prev[0], prev[2] - prices[i]);
            curr[1] = prices[i] + prev[0];
            curr[2] = max(prev[1], prev[2]);

            prev = curr;
        }

        return max(prev[1], prev[2]);
        
    }
};