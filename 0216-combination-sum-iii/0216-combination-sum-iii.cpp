class Solution {
public:
    void helper(int k, int n, vector<vector<int>> &ans, vector<int> temp, int sum, int start)
    {
        if(temp.size() == k && sum == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=start; i<=9; i++)
        {
            temp.push_back(i);
            helper(k, n, ans, temp, sum + i, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(k, n, ans, temp, 0, 1);

        return ans;
    }
};