class Solution {
public:

    int findFirstOccurrence(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int first = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                if (nums[m] == target) first = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return first;
    }


    int findLastOccurrence(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int last = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                if (nums[m] == target) last = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return last;
    }

    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstOccurrence(nums, target);
        int last = findLastOccurrence(nums, target);
        return {first, last};
    }
};
