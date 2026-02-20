class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; 

        for(int num : nums)
        {
            pq.push(num);
        }

        int count = 1;
        while(count < k)
        {
            pq.pop();
            count++;
        }

        return pq.top();
    }
};