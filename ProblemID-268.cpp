class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        long long int s = nums.size();
        vector<int>hash(s+1, 0);
        int n = 0;

        for(int i=0; i<s; i++)
        {
            hash[nums[i]] += 1;
        }

        for(int i=0; i<s+1; i++)
        {
            if(hash[i] == 0)
            n = i;
        }

        return n;
    }
};
