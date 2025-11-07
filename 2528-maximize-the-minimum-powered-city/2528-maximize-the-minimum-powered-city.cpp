class Solution {
private:
    bool possible(vector<long long>& power, int r, long long k, long long mid) {
        int n = power.size();
        vector<long long> added(n + 1, 0);
        long long extra = 0;
        long long used = 0;

        for (int i = 0; i < n; i++) {
            extra += added[i]; // apply previous influence changes

            if (power[i] + extra < mid) {
                long long need = mid - (power[i] + extra);
                used += need;
                if (used > k) return false;

                extra += need; // new stations start affecting now
                if (i + 2 * r + 1 < n)
                    added[i + 2 * r + 1] -= need; // their effect ends later
            }
        }

        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> power(n, 0);
        vector<long long> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            diff[max(0, i - r)] += stations[i];
            diff[min(n, i + r + 1)] -= stations[i];
        }

        power[0] = diff[0];
        for (int i = 1; i < n; i++)
            power[i] = power[i - 1] + diff[i];

        long long low = 0;
        long long high = *max_element(power.begin(), power.end()) + k;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (possible(power, r, k, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};
