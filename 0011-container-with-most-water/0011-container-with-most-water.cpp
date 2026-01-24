class Solution {
public:
    int maxArea(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int maxArea = INT_MIN;

        while(l < r)
        {
            int dist = r - l; 
            maxArea = max(maxArea, dist * min(nums[l] , nums[r]));

            if(nums[l] < nums[r])
            l++;
            else
            r--;
        }

        return maxArea;
    }
};