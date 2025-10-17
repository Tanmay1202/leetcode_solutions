class Solution {
private:
    int atMostK(vector<int>& nums, int k)
    {
        int left = 0, count = 0, odd = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] % 2 != 0) odd++;

            while (odd > k)
            {
                if (nums[left] % 2 != 0) odd--;
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
