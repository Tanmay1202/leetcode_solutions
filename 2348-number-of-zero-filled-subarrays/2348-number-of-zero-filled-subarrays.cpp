class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long count = 0;
        unordered_map<int, int> freq;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                count++;
                freq[count]++;
            }
            else
            {
                count = 0;
            }
        }

        long long ans = 0;

        for(auto &it: freq)
        {
            ans += it.second * it.first;
        }

        return ans;

    }
};