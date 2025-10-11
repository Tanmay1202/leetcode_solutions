class Solution {
private:
    int upperBound(vector<long long> &vec, int low, int high, long long limit)
    {
        while(low < high)
        {
            int mid = low + (high - low)/2;

            if(vec[mid] <= limit)
            {
                low = mid + 1;
            }
            else
                high = mid;
        }

        return high;
    }
public:
    long long maximumTotalDamage(vector<int>& power) 
    {
        unordered_map<int, int> freq;

        for(auto x : power)
        {
            freq[x]++;
        }

        vector<long long> unique;

        for(auto x: freq)
        {
            unique.push_back(x.first);
        }

        sort(unique.begin(), unique.end());
        
        vector<int> nextValidIndex(unique.size());

        int n = unique.size();

        
        for(int i=0; i<unique.size(); i++)
        {
            nextValidIndex[i] = upperBound(unique, i+1, n, unique[i] + 2);
        }

        vector<long long> dp(n+1);
        dp[n] = 0;

        for(int i=n-1; i>=0; i--)
        {
            // FIX: Don't access unique[nextValidIndex[i]] - just use the dp value
            dp[i] = max(dp[i+1], (long long)unique[i] * freq[unique[i]] + dp[nextValidIndex[i]]);
        }

        return dp[0];

    }
};