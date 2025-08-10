class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> maxDp(n);
        vector<int> minDp(n);

        maxDp[0] = minDp[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            maxDp[i] = max(nums[i], max(maxDp[i-1]*nums[i], minDp[i-1]*nums[i]));
            minDp[i] = min(nums[i], min(maxDp[i-1]*nums[i], minDp[i-1]*nums[i]));
        }


        return *max_element(maxDp.begin(), maxDp.end());
    }
};