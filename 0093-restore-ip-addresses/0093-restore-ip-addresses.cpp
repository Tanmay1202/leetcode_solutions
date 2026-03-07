class Solution {
private:
    bool isValid(string &s, int end, int start)
    {
        if(s[start] == '0' && end > start) return false; 
        int len = end - start + 1;

        int num = stoi(s.substr(start, len));
        
        return num >= 0 && num <= 255;
    }
    void backtrack(vector<string> &result, string &temp, int start, string &s, int parts)
    {
        if(parts == 4 && start == s.size())
        {
            result.push_back(temp);
            return;
        }

        if(parts == 4) return;

        for(int i=start; i<min(start + 3, (int)s.size()); i++)
        {
            if(isValid(s, i, start))
            {
                int len = temp.size();
                if(parts > 0) temp += '.';
                temp += s.substr(start, i - start + 1);
                backtrack(result, temp, i+1, s, parts + 1);
                temp = temp.substr(0, len);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string temp;

        backtrack(result, temp, 0, s, 0);

        return result;
    }
};