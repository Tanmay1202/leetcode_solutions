class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ones = 0;
        int twos = 0;

        for(int num : nums)
        {
            twos |= ones & num;
            ones ^= num;

            int common = ~(ones & twos);

            ones &= common;
            twos &= common;
            
        }

        return ones;
    }
};