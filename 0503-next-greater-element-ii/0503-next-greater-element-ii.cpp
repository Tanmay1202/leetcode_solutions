class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> result(n, -1);
        vector<int> st;            // use vector as stack (store indices)
        st.reserve(n);

        for (int i = 2 * n - 1; i >= 0; --i) {
            int idx = i % n;
            while (!st.empty() && nums[st.back()] <= nums[idx]) st.pop_back();
            if (!st.empty()) result[idx] = nums[st.back()];
            st.push_back(idx);
        }

        return result;
    }
};
