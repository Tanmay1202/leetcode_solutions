class Solution {
private:
    // vector<int> best;
    vector<vector<vector<int>>> dp;

    vector<int> memo(int index, int prevIndex, vector<int>& nums) {
        if (index == nums.size()) {
            return {};
        }

        if (!dp[index][prevIndex + 1].empty())
            return dp[index][prevIndex + 1];

        vector<int> skip = memo(index + 1, prevIndex, nums);

        vector<int> take;

        if (prevIndex == -1 || nums[index] % nums[prevIndex] == 0) {
            take = memo(index + 1, index, nums);
            take.push_back(nums[index]);
        }

        return dp[index][prevIndex + 1] = (take.size() > skip.size()) ? take : skip;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp.assign(n+1, vector<vector<int>>(n+1));
        return memo(0, -1, nums);
    }
};