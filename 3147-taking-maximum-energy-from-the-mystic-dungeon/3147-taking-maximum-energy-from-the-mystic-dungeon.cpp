class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) 
    {
        vector<int> dp(energy.size());

        for(int i=energy.size() - 1; i>=0; i--)
        {
            if(i + k <= energy.size() - 1)
            dp[i] = energy[i] + dp[i+k];
            else
            dp[i] = energy[i];
        }


        return *max_element(dp.begin(), dp.end());
    }
};