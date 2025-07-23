class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> seen;
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right<s.size(); right++)
        {
            while(seen.find(s[right]) != seen.end())
            {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};