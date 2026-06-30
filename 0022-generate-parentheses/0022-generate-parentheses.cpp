class Solution {
public:
    void helper(int open, int close, vector<string> &ans, string temp,int n)
    {
        if(temp.size() == n*2)
        {
            ans.push_back(temp);
            return;
        }

        if(open < n)
        helper(open+1, close, ans, temp + '(', n);

        if(close < open)
        helper(open, close+1, ans, temp + ')', n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        helper(0, 0, ans, temp, n);

        return ans;
    }
};