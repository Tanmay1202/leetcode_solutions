class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int prof = 0;
        int profi = 0;

        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] - buy > 0)
            prof = max(prof, prices[i] - buy);
            profi = prices[i] - buy;
            buy = min(buy, prices[i]);
        } 

        return prof;
    }
};