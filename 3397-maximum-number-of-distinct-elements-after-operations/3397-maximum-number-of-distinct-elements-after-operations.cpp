class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, long long> nextFree;
        
        function<long long(long long)> find = [&](long long v) -> long long {
            if(nextFree.find(v) == nextFree.end()) return v;
            return nextFree[v] = find(nextFree[v]);
        };
        
        int count = 0;
        for(long long x : nums) {
            long long val = find(x - k);
            if(val <= x + k) {
                nextFree[val] = find(val + 1);
                count++;
            }
        }
        return count;
    }
};
