class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int> temp, vector<vector<int>> &ans, int index)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(index == candidates.size() || target < 0)
        return;

        //take
        if(candidates[index] <= target)
        {
            temp.push_back(candidates[index]);
            helper(candidates, target - candidates[index], temp, ans, index+1);
            temp.pop_back();
        }


        //not take
        int next = index + 1;

        while(next < candidates.size() && candidates[index] == candidates[next])
        next++;

        helper(candidates, target, temp, ans, next);


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;


        sort(candidates.begin(), candidates.end());

        helper(candidates, target, temp, ans, 0);

        return ans;
    }
};