class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> targetFreq(128, 0);
        vector<int> windowFreq(128, 0);

        for (char c : t) targetFreq[c]++;

        int left = 0;
        int minStart = -1;
        int minLength = n + 1;
        int validCount = 0;

        for (int right = 0; right < n; right++) {
            char rc = s[right];
            windowFreq[rc]++;

            if (windowFreq[rc] <= targetFreq[rc])
                validCount++;

            while (validCount == m) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minStart = left;
                }

                char lc = s[left];
                if (windowFreq[lc] == targetFreq[lc])
                    validCount--;

                windowFreq[lc]--;
                left++;
            }
        }

        if (minStart == -1) return "";
        return s.substr(minStart, minLength);
    }
};
