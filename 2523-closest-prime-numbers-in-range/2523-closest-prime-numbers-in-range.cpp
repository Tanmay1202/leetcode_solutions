class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);

        isPrime[0] = false;
        if(right<=1)
        isPrime[1] = false;

        for(int i=2; i*i<=right; i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i; j<=right; j+=i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int minDiff = INT_MAX;
        vector<int> ans(2, -1);
        int prev = -1;


        for(int i=max(2,left); i<isPrime.size(); i++)
        {
            if(isPrime[i])
            {
                if(prev != -1 && i - prev < minDiff)
            {
                minDiff = i - prev;
                ans[0] = prev;
                ans[1] = i;
            }
            prev = i;
            }

            
        }

        return ans;


    }
};