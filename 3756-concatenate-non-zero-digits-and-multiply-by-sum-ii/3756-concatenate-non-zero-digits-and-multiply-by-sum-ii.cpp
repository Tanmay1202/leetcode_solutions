class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        vector<int> positions;
        vector<int> digits;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != '0')
            {
                int num = s[i] - '0';
                digits.push_back(num);
                positions.push_back(i);
            }
        }

        int n = digits.size();

        if(n == 0)
        {
            return vector<int>(queries.size(), 0);
        }

        vector<int> prefixSum(n, 0);
        vector<long long> prefixNum(n);
        vector<long long> pow10(n + 1);

        pow10[0] = 1;
        for(int i=1; i<=n; i++)
        {
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        if(n > 0)
        {
            prefixSum[0] = digits[0];
            prefixNum[0] = digits[0];

            for(int i=1; i<digits.size(); i++)
            {
                prefixSum[i] = prefixSum[i-1] + digits[i];
                prefixNum[i] = (prefixNum[i-1]*10 + digits[i]) % MOD;
            }
        }


        vector<int> ans;
        for(auto &q: queries)
        {
            int l = q[0];
            int r = q[1];

            int left = lower_bound(positions.begin(), positions.end(), l) - positions.begin();
            int right = upper_bound(positions.begin(), positions.end(), r) - positions.begin() - 1;

            if(left > right || left >= n)
            {
                ans.push_back(0);
                continue;
            }

            int len = right - left + 1;

            long long number;
            int sum;

            if(left == 0)
            {
                number = prefixNum[right];
                sum = prefixSum[right];
            }
            else
            {
                number = (prefixNum[right] - prefixNum[left - 1] * pow10[len] % MOD + MOD) % MOD;
                sum = prefixSum[right] - prefixSum[left - 1];

            }

            ans.push_back((number * sum) % MOD);
        }


        return ans;
    }
};