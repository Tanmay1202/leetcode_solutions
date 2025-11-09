class Solution {
private:
    bool isPalindrome(string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            return false;
        }

        return true;
    }

    void backtrack(string &s, vector<string> temp, vector<vector<string>> &result, int start)
    {
        if(start == s.size())
        {
            result.push_back(temp);
            return;
        }

        for(int i=start; i<s.size(); i++)
        {
            if(isPalindrome(s, start, i))
            {
                temp.push_back(s.substr(start, i - start + 1));
                backtrack(s, temp, result, i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) 
    {
        vector<string> temp;
        vector<vector<string>> result;

        backtrack(s, temp, result, 0);

        return result;
    }
};