class Solution {
private:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, int sum, vector<int> temp, int start)
    {
        if(sum > target)
        return; 

        
        if(sum == target)
        {
            result.push_back(temp);
            return;
        }

        for(int i=start; i<candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            backtrack(candidates, target, result, sum+candidates[i], temp, i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> temp;

        backtrack(candidates, target, result, 0, temp, 0);

        return result;
    }
};