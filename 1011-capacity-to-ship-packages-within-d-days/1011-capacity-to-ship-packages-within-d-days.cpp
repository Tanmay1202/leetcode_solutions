class Solution {
private:
    bool possible(vector<int>& weights, int days, int mid)
    {
        int count = 1;
        int sum = 0;

        for(int i=0; i<weights.size(); i++)
        {
            if(sum + weights[i] > mid)
            {
                count++;
                sum = 0;
            }

            sum += weights[i];
        }

        return count <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(possible(weights, days, mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};