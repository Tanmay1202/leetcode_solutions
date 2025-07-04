class Solution {
private:
    void backtrack(vector<int>&nums, vector<vector<int>>&result, vector<int>&temp, int start)
    {
        result.push_back(temp);

        for(int i=start; i<nums.size(); i++)
        {
            if(i>start && nums[i] == nums[i-1])
            continue;

            temp.push_back(nums[i]);
            backtrack(nums, result, temp, i+1);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> temp;

        backtrack(nums, result, temp, 0);

        return result;
    }
};