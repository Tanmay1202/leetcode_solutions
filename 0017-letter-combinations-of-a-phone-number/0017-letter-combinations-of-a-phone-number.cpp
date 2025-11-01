class Solution {
privat:
    void backtrack(string digits, vector<string>& result, string temp, int i, unordered_set<int, string>&  map)
    {
        if(i == digits.size())
        {
            result.push_back(temp);
            return;
        }

        int x = digits[i] - '0';
        string s = mp[x];

        for(int i=0; i<s.size(); i++)
        {
            temp.push_back(s[i]);
            backtrack(digits, result, temp, i+1, map);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string temp;

        unordered_map<int, string> mp;
        int j = 97;

        for (int i = 2; i <= 9; i++) {
            string s = "";
            int count = (i == 7 || i == 9) ? 4 : 3;
            for (int k = 0; k < count; k++) {
                s += char(j++);
            }
            mp[i] = s;
        }


        backtrack(digits, result, temp, 0, mp);

        return result;


    };