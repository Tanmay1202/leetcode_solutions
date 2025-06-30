class Solution {
public:
    bool possible(int days, int weight, vector<int>& nums) {
        int count = 1;
        int current = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (current + nums[i] > weight) {
                count++;
                current = 0;
            }
            current += nums[i];
        }

        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = *max_element(weights.begin(), weights.end());
        int sumWeight = accumulate(weights.begin(), weights.end(), 0);

        int low = maxWeight, high = sumWeight, ans = sumWeight;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(days, mid, weights)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
