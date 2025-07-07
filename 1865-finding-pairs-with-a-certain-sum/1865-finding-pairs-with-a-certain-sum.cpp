class FindSumPairs {
private:
    unordered_map<int, int> freq2;
    vector<int> nums1;
    vector<int> nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int num : nums2)
        {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] = nums2[index] + val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;

        for(int i=0; i<nums1.size(); i++)
        {
            int diff = tot - nums1[i];
            if(freq2.count(diff))
            {
                count += freq2[diff];
            }
        }

        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */