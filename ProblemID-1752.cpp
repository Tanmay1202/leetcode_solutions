class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int s = nums.size();

        for(int i=0; i<s; i++)
        {
            bool o = sorted(nums);
            if(o)
            return true;
            int last = nums[s-1];
            for(int j=s-1; j>0; j--)
            {
                nums[j] = nums[j-1];
            }
            nums[0] = last;
        }

        return false;
    }

    bool sorted(vector<int>& arr)
    {
        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr[i+1]<arr[i])
            return false;
        }
        return true;
    }
};