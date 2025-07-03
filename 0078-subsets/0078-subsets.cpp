class Solution {
private:
    void recursion(vector<int>& nums, int start, vector<int> &temp, vector<vector<int>> &res)
    {
        res.push_back(temp);

        for(int i= start; i<nums.size(); i++)
        {
            temp.push_back(nums[i]);

            recursion(nums, i+1, temp, res);

            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> temp;
        vector<vector<int>> res;

        recursion(nums, 0, temp, res);

        return res;
    }
};