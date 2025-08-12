class Solution {
public:
    // compute a^b, but stop and return limit+1 if it exceeds limit
    static long long powerLimit(int a, int b, int limit) {
        long long res = 1;
        for (int i = 0; i < b; ++i) {
            if (res > limit / a) return (long long)limit + 1;
            res *= a;
        }
        return res;
    }

    int numberOfWays(int n, int x) {
        const int MOD = 1000000007;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int base = 1; ; ++base) {
            long long wt = powerLimit(base, x, n);
            if (wt > n) break;
            for (int j = n; j >= wt; --j) {
                dp[j] += dp[j - wt];
                if (dp[j] >= MOD) dp[j] -= MOD;
            }
        }

        return dp[n];
    }
};
