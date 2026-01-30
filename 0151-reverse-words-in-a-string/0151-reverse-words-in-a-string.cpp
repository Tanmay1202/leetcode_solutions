class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') i++;   
            if (i >= n) break;

            if (j > 0) s[j++] = ' ';           

            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
        }

        s.resize(j);

    
        reverse(s.begin(), s.end());

        
        int start = 0;
        for (int k = 0; k <= j; k++) {
            if (k == j || s[k] == ' ') {
                reverse(s.begin() + start, s.begin() + k);
                start = k + 1;
            }
        }

        return s;
    }
};
