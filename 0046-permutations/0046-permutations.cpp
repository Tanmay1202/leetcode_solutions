class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& temp, vector<int> &nums)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(!(find(temp.begin(), temp.end(), nums[i]) != temp.end()))
            {
                temp.push_back(nums[i]);
                backtrack(ans, temp, nums);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(ans, temp, nums);

        return ans;
    }
};