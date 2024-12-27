class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int s = nums.size();
        int i = 0;
        for(int j=0; j<s; j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};