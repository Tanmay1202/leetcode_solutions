class Solution {
private:
    void backtrack(string temp, vector<string>& res, int open, int close,int n)
    {
        if(temp.size() == n*2)
        {
            res.push_back(temp);
            return;
        }

        if(open<n)
        backtrack(temp+'(', res, open+1, close, n);

        if(close < open)
        backtrack(temp+')',res, open, close+1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> res;

        backtrack(temp, res, 0, 0, n);

        return res;
    }
};