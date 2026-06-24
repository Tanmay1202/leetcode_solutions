class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qu;
        vector<int> ans;

        int n = nums.size();

        for(int i=0; i<k; i++)
        {
            while(!qu.empty() && nums[i] > nums[qu.front()])
            qu.pop_front();

            while(!qu.empty() && nums[i] > nums[qu.back()])
            qu.pop_back();

            qu.push_back(i);
        }


        if(!qu.empty()) ans.push_back(nums[qu.front()]);

        for(int i=k; i<n; i++)
        {
            if(i-k == qu.front()) qu.pop_front();

            while(!qu.empty() && nums[i] > nums[qu.front()])
            qu.pop_front();

            while(!qu.empty() && nums[i] > nums[qu.back()])
            qu.pop_back();

            qu.push_back(i);


            ans.push_back(nums[qu.front()]);
        }


        return ans;
    }
};