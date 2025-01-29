class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int s = nums.size();
        int arr[s];
        int j=0;
        for(int i=0; i<s; i++)
        {
            if(nums[i]!=val)
            {
                arr[j] = nums[i];
            }
            j++;
        }
        for(int i=0; i<j; i++)
        {
            nums[i] = arr[j];
        }
    }
};