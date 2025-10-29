class Solution {
private:
    void backtrack(vector<int>& nums, vector<vector<int>> &result, vector<int> temp, int start)
    {
        result.push_back(temp);

        for(int i=start; i<nums.size(); i++)
        {
            temp.push_back(nums[i]);
            backtrack(nums, result, temp, i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> temp;

        backtrack(nums, result, temp, 0);

        return result;
    }
};