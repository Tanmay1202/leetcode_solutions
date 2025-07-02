class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> pref(n,1);
        vector<int> suff(n,1);
        vector<int> res(n);
        for(int i=1; i<n; i++)
        {
            int prod = nums[i-1]*pref[i-1];
            pref[i] = prod;
        }

        for(int i=n-2; i>=0; i--)
        {
            int prod = nums[i+1]*suff[i+1];
            suff[i] = prod;
        }

        for(int i=0; i<n; i++)
        {
            res[i] = pref[i] * suff[i];
        }

        return res;


        
    }
};