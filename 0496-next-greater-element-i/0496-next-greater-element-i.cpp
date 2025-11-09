class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater;
        vector<int> result;

        for(int i=0; i<nums2.size(); i++)
        {
            while(!st.empty() && nums2[i] > st.top())
            {
                int top = st.top();
                nextGreater[top] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        while(!st.empty())
        {
            int top = st.top();
            nextGreater[top] = -1;
            st.pop();
        }

        for(int i=0; i<nums1.size(); i++)
        {
            if(nextGreater.count(nums1[i]) != 0)
            {
                result.push_back(nextGreater[nums1[i]]);
            }
        }


        return result;


        
    }
};