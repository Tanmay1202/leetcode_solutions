class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int cnt = 0;
        int cmax = 0;
        for(int i=0; i<nums.size(); i++)
        {
            cnt++;
            if(nums[i]==1)
            {
                if(cnt > cmax)
                cmax = cnt;
            }
            else
            {
                cnt = 0;
            }
        }

        return cmax;
    }
};