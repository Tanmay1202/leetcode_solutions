class Solution {
private:
    void backtrack(vector<int> candidates, int target, vector<int> temp, vector<vector<int>>& result, int start, int sum)
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
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            temp.push_back(candidates[i]);
            backtrack(candidates, target, temp, result, i+1, sum+candidates[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<int> temp;
        vector<vector<int>> result;

        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, temp, result, 0, 0);
        
        return result;

    }
};