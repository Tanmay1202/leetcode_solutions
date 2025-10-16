class Solution {
private:
    bool possible(vector<int>& nums, int k, int mid)
    {
        int count = 1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(sum + nums[i] > mid)
            {
                sum = 0;
                count++;
            }
            sum+= nums[i];
        }

        return count <= k;

    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }


        return low;
    }
};