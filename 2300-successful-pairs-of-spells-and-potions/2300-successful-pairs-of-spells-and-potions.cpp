class Solution {
private:
    long long lowerBound(int key, const vector<int>& potions)
    {
        long long low = 0;
        long long high = potions.size();

        while(low < high)
        {
            long long mid = low + (high - low)/2;
            if((long long)potions[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }


        return low;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> pairs(spells.size());

        sort(potions.begin(), potions.end());

        for(int i=0; i<spells.size(); i++)
        {
            int s = spells[i];

            long long p_min = (success + (long long)s - 1)/(long long)s;

            int lower = lowerBound(p_min, potions);

            int count = potions.size() - lower;

            pairs[i] = count;
        }




        return pairs;
    }
};