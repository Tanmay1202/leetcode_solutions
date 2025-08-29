class Solution {
private:
    bool possible(vector<int>& bloomDay, int m, int k, int mid)
    {
        int bouqets = 0;
        int flowers = 0;


        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= mid)
            {
                flowers++;

                if(flowers == k)
                {
                    bouqets++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }

        }


        return bouqets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        if ((long long)k * m > bloomDay.size()) return -1;

        while(low < high)
        {
            int mid = low + (high - low)/2;

            if(possible(bloomDay, m, k, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return high;
    }
};