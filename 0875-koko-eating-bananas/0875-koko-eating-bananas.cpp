class Solution {
public:
    bool possible(int mid, vector<int>& piles, int h)
    {
        int hours = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            
            hours += ceil(double(piles[i])/mid);
        }

        
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end()); 
        // int ans = 0;

        while(low < high)
        {
            int mid = low + (high - low) / 2;


            if(possible(mid, piles, h))
            {
                high = mid;
            }
            else
            {
                low = mid + 1; 
            }
        }

        return low; 
    }
};
