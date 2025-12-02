class Solution {
private:
    int nCr(long long n)
    {
        if(n < 2)
        return 0;

        return (n*(n-1))/2;

    }
public:
    int countTrapezoids(vector<vector<int>>& points) {

        unordered_map<long long, long long>yFreq;
        const long long mod = 1000000007;
        for(auto &it: points)
        {
            yFreq[it[1]]++;
        }

        vector<long long> ways;

        for(auto &it: yFreq)
        {
            ways.push_back(nCr(it.second) % mod);
        }

        long long ans = 0;
        int m = ways.size();

        for(int i=0; i<m; i++)
        {
            for(int j=i+1; j<m; j++)
            {
                ans += (ways[i]*ways[j] % mod) % mod;
            }
        }

        return ans%mod;
    }
};