class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = count(nums.begin(), nums.end(), 1);

        if (k <= 1) return 0;

        int zeroCount = 0;

        // first window
        for (int i = 0; i < k; i++) {
            if (nums[i] == 0) zeroCount++;
        }

        int ans = zeroCount;

        // slide window circularly
        for (int i = k; i < n + k; i++) {
            if (nums[i % n] == 0) zeroCount++;
            if (nums[(i - k) % n] == 0) zeroCount--;

            ans = min(ans, zeroCount);
        }

        return ans;
    }
};
