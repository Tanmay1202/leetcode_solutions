class Solution {
private:
    void backtrack(int k, int n, vector<int> temp, vector<vector<int>>& result, int start, int sum)
    {
        if(temp.size() == k)
        {
            if(sum == n) 
            result.push_back(temp);
            

            return;
        }

        for(int i=start; i<=9; i++)
        {
            temp.push_back(i);
            backtrack(k, n, temp, result, i+1, sum+i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> result;

        backtrack(k, n, temp, result, 1, 0);

        return result;
    }
};