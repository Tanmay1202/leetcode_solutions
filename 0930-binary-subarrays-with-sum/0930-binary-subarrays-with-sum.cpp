class Solution {
private:
    int sumBinary(vector<int>&nums, int k)
    {
        if(k < 0) return 0;
        int left = 0;
        int sum = 0;
        int count = 0;

        for(int right=0; right<nums.size(); right++)
        {
            sum += nums[right];

            while(sum > k)
            {
                sum -= nums[left];
                left++;
            }

            if(sum <= k)
            {
                count += right - left + 1;
            }
        }


        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        return sumBinary(nums,k) - sumBinary(nums,k-1);
    }
};