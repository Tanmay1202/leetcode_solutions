class Solution {
public:
    bool possible(vector<int>& piles, int h, int mid)
    {
        int n = piles.size();
        int hours = 0;

        for(int i=0; i<n; i++)
        {
            hours += ceil((double)piles[i]/mid);
        }

        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high)
        {

            int mid = low + (high - low)/2;

            if(possible(piles, h, mid))
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