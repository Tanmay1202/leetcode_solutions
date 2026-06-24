class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        int n = s.size();
        if(k > n) return {};
        unordered_map<char, int> targetFreq;
        unordered_map<char, int> windowFreq;

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            targetFreq[p[i]]++;
            windowFreq[s[i]]++;
        }

        if (windowFreq == targetFreq)
            ans.push_back(0);

        for (int i = k; i < n; i++) {
            windowFreq[s[i]]++;
            windowFreq[s[i - k]]--;

            if (windowFreq[s[i - k]] == 0)
                windowFreq.erase(s[i - k]);
            // targetFreq[p[i]]++;

            if (windowFreq == targetFreq)
                ans.push_back(i - k + 1);
        }

        return ans;
    }
};