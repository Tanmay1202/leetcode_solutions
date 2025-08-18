class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = nums[0];
        int prevMax = nums[0];
        int prevMin = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
            int temp = prevMax;
            prevMax = max(nums[i], max(nums[i]*temp, nums[i]*prevMin));
            prevMin = min(nums[i], min(nums[i]*temp, nums[i]*prevMin));

            ans = max(ans, prevMax);
        }

        return ans;
    }
};