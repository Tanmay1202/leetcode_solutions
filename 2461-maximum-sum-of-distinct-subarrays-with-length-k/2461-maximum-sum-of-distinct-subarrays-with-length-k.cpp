class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int left = 0;
        long long maxSum = 0;
        long long sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (seen.count(nums[right]) || right - left >= k) {
                seen.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            seen.insert(nums[right]);
            sum += nums[right];

            if (right - left + 1 == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
