class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target)
            return mid;
            else if(nums[mid]<target)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return left;



        // int j=0;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     if(nums[i]==target)
        //     return i;

        //     if(nums[i]<target)
        //     {
        //         j = i+1;
        //     }
        // }
        // return j;

        
    }
};