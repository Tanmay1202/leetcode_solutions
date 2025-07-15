class Solution {
public:
    bool possible(vector<int>& weights, int days, int mid)
    {
        int current = 0;
        int count = 1;

        for(int i=0; i<weights.size(); i++)
        {
            if(current + weights[i] > mid)
            {
                count++;
                current = 0;
            }

            current += weights[i];
        }

        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high)
        {
            int mid = low + (high - low)/2;

            if(possible(weights, days, mid))
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }

        return high;
    }
};