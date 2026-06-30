class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> windowFreq;
        int left = 0;

        int ans = 0;

        for(int right = 0; right < s.size(); right++)
        {
            windowFreq[s[right]]++;
            while(windowFreq['a'] > 0 && windowFreq['b'] > 0 && windowFreq['c'] > 0 )
            {
                windowFreq[s[left]]--;
                left++;
            }

            ans += left;
        }

        return ans;
    }
};