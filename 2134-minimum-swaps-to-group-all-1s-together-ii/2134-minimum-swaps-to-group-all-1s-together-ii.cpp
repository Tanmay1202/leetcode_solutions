class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int zeroCount = 0;
        int ans = INT_MAX;


        int k = count(nums.begin(), nums.end(), 1);


        for(int i=0; i<k; i++)
        {
            if(nums[i] == 0) zeroCount++;
        }

        for(int i=k; i<n + k; i++)
        {
            if(nums[(i-k)%n] == 0) zeroCount--;
            if(nums[i%n] == 0)zeroCount++;


            ans = min(ans, zeroCount);
        }

        return ans;

    }
};