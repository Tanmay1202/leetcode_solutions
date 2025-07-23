class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        unordered_map<int, int> sumCount;
        int sum = 0;
        int count = 0;

        for(int i=0; i<nums.size()-1; i++)
        {
            sum = nums[i] + nums[i+1];
            if(sumCount.find(sum) != sumCount.end())
            {
                return true;
            }

            sumCount[sum]++;
        }

        return false;
    }
};