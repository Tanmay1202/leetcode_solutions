class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        //int ans = -1;

        for(int i=0; i<nums.size(); i++)
        {
            int diff = i - start;
            if(nums[i] == target && ans > abs(i - start))
            {
                //minDis = abs(i - start);
                ans = abs(i-start);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};