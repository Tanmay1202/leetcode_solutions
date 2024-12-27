class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();

        k = k % n;

        reverse(nums, 0, n-1);

        reverse(nums, 0, k-1);

        reverse(nums, k, n-1);
    //     for(int i=0; i<k; i++)
    //     {
    //         int last = nums[n-1];
    //         for(int j=n-1; j>0; j--)
    //         {
    //             nums[j] = nums[j-1];
    //         }
    //         nums[0] = last;
    //     }
    }

    void reverse(vector<int>& arr, int s, int e)
    {

        while(s<e)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
};