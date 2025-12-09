class Solution {
public:
    int specialTriplets(vector<int>& nums) 
    {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;

        long long ans = 0;

        for(int x : nums)
        {
            right[x]++;
        }

        for(int i=0; i<nums.size(); i++)
        {
            int mid = nums[i];
            right[mid]--;

            long long need = mid * 2LL;

            long long leftCount = left[need];
            long long rightCount = right[need];

            ans = (ans + (leftCount * rightCount) % MOD) % MOD;


            left[mid]++;
        }

        return (int)ans;
    }
};