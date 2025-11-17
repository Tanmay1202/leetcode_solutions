class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int index = -1;

        bool flag = false;

        for(int i=0; i<n; i++)
        {
            if(nums[i] == 1)
            {
                if(index != -1 && i - index - 1 < k)
                return false;

                index = i;
            }
        }

        return true;
    }
};