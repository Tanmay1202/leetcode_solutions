class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = 0;
        int j = 0;

        vector<int> result;

        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m)
        {
            result.push_back(nums1[i]);
            i++;
        }

        while(j < n)
        {
            result.push_back(nums2[j]);
            j++;
        }

        for(int k = 0; k < result.size(); k++)
        {
            nums1[k] = result[k];
        }
    }
};
