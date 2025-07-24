class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int mini = prices[0];
        // int prof = 0;
        int maxProf = 0;

        for(int i=1; i<n; i++)
        {
            int prof = prices[i] - mini;
            maxProf = max(prof, maxProf);
            mini = min(prices[i], mini);
        }


        return maxProf;
    }
};