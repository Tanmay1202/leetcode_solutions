class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
            int tempMax = maxProd;
            maxProd = max(nums[i], max(minProd*nums[i], tempMax*nums[i]));
            minProd = min(nums[i], min(minProd*nums[i], tempMax*nums[i]));

            ans = max(maxProd, ans);
        }

        return ans;
    }
};