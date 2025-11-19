class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> mySet(nums.begin(), nums.end());
        int fin = original;

        while(mySet.count(fin))
        {
            fin *= 2;
        }

        return fin;
    }
};