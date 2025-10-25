class Solution {
private:
    void backtrack(long long& ans, int i, string& s) {
        if (i >= s.size() || !isdigit(s[i])) {
            return;
        }

        ans = ans*10 + s[i] - '0';

        backtrack(ans, i + 1, s);
    }

public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;
        int i = 0;
        bool neg = false;
        while (i < s.size() && s[i] == ' ')
            i++;

        if(i >= s.size()) return 0;

        if(s[i] == '-')  
        {
            i++;
            neg = true;
        }
        else if(s[i] == '+')
        {
            i++;
            neg = false;
        }
        backtrack(ans, i, s);

        if(neg) ans = -ans;


        if(ans > INT_MAX) ans = INT_MAX;
        if(ans < INT_MIN) ans = INT_MIN;


        return (int)ans;
    }
};