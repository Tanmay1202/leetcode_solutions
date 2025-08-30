class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int s = nums.size();
        int index = 0;
        for(int i=0; i<s; i++)
        {
            if(nums[index] != nums[i])
            {
                index = index + 1;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};