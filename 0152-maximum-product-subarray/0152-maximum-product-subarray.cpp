class Solution {
private:
    void backtrack(vector<int>& nums, int &ans, int start, int prod)
    {
        for(int i=start; i<nums.size(); i++)
        {
            prod *= nums[i];
            ans = max(prod, ans);
            backtrack(nums, ans, i+1, prod);
        }
    }

public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];

        backtrack(nums, ans, 0, 1);

        return ans;
    }
};