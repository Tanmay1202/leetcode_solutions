class Solution {
public:
    string helper(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '#') {
                if(!st.empty()
                )
                st.pop();
            } else {
                st.push(c);
            }
        }
        string sres = "";

        while (!st.empty()) {
            sres.push_back(st.top());
            st.pop();
        }

        reverse(sres.begin(), sres.end());

        return sres;
    }
    bool backspaceCompare(string s, string t) {
        string sres = helper(s);
        string tres = helper(t);

        return sres == tres;
    }
};