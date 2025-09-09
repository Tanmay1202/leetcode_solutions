class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9+7;
        vector<long long> dp(n+1, 0); // dp[i] = people who learn on day i
        dp[1] = 1; // day 1, one person learns

        for (int day = 2; day <= n; day++) {
            for (int j = max(1, day - forget + 1); j <= day - delay; j++) {
                dp[day] = (dp[day] + dp[j]) % MOD;
            }
        }

        long long total = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            total = (total + dp[day]) % MOD;
        }

        return total;
    }
};
