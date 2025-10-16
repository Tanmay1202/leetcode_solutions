class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        unordered_map<int, int> count;

        for(auto num: nums)
        {
            int r = ((num % value) + value) % value;
            count[r]++;
        }

        int m = 0;


        while(true)
        {
            if(count[m%value]) count[m%value]--;
            else if(count[m%value] == 0) return m;

            m++;
        }

        return -1;
    }
};