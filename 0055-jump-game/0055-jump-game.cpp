class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();

        int reached = n-1;

        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] + i >= reached)
            reached = i;

            
        }

        if(reached == 0)
        return true;

        return false;
    }
};