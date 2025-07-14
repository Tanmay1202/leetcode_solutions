class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();

        if(n==1)
        return nums[0];

        int jump = 1;
        int stop = 0;
        int dest = 0;

        for(int i=0; i<n; i++)
        {
            stop = i + nums[i];
            dest = nums[i + nums[i]];
            for(int j=i; j<nums[i]; j++)
            {
                if(nums[j] + j >= stop && nums[j + nums[j]] <= nums[n-1])
                {
                    stop = nums[j] + j;
                    dest = nums[stop];
                    jump++;
                }
            }

            if(dest == nums[n-1])
            return jump- 1;
        }


        return -1;
    }
};