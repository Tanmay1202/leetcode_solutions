class Solution {
private:
    bool possible(vector<int>& piles, int h, int mid)
    {
        long count = 0;

        for(int i=0; i<piles.size(); i++)
        {
            count += ceil((double)piles[i]/mid);
        }

        return count <= h;

    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
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


        return low;
    }
};