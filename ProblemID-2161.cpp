class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot)
        {
            vector<int> arr1;
            vector<int> arr2;
            vector<int> arr3;
    
            for(auto& it: nums)
            {
                if(it<pivot)
                {
                    arr1.push_back(it);
                }
                else if(it == pivot)
                {
                    arr2.push_back(it);
                }
                else
                {
                    arr3.push_back(it);
                }
            }
    
            int j=0;
            for(int i=0; i<arr1.size(); i++)
            {
                nums[j] = arr1[i];
                j++;
            }
    
            for(int i=0; i<arr2.size(); i++)
            {
                nums[j] = arr2[i];
                j++;
            }
    
            for(int i=0; i<arr3.size(); i++)
            {
                nums[j] = arr3[i];
                j++;
            }
    
            return nums;
        }
    };

    