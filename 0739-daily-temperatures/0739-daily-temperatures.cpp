class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> answer(n, 0);

        for(int i=0; i<n; i++)
        {
            while(!s.empty() && nums[i] > nums[s.top()])
            {
                int prevIndex = s.top();
                s.pop();
                answer[prevIndex] = i - prevIndex;
            }
            s.push(i);
        }

        return answer;

    }
};