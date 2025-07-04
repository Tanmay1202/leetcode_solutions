class Solution {
private:
    void backtrack(vector<string> &ans, string temp, int n, int open, int close)
    {
        if(temp.size() == 2*n)
        {
            ans.push_back(temp);
            return;
        }

        if(open < n)
        {
            backtrack(ans, temp + '(', n, open+1, close);
        }

        if(close < open)
        {
            backtrack(ans, temp+')', n, open, close+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;

        backtrack(ans, "", n, 0, 0);

        return ans;
    }
};