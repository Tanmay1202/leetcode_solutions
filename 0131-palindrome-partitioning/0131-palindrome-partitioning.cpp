class Solution {
private:
    // Check palindrome using stack but with indices (no substr)
    bool isPalindrome(const string &s, int left, int right) {
        stack<char> st;

        for (int i = left; i <= right; i++) {
            st.push(s[i]);
        }

        for (int i = left; i <= right; i++) {
            if (st.top() != s[i])
                return false;
            st.pop();
        }

        return true;
    }

    void backtrack(vector<vector<string>> &result, vector<string> &temp, const string &s, int start) {
        if (start == s.length()) {
            result.push_back(temp);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // Efficient string creation using constructor with start & length
                temp.push_back(string(s.begin() + start, s.begin() + end + 1));
                backtrack(result, temp, s, end + 1);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        backtrack(result, temp, s, 0);
        return result;
    }
};
