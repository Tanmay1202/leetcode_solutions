class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int s = prices.size();
        int mini = prices[0];
        int max_prof = 0;
        for(int i=0; i<s; i++)
        {
            int cost = prices[i] - mini;
            max_prof = max(max_prof, cost);
            mini = min(mini, prices[i]);
        }
        return max_prof;
    }
};