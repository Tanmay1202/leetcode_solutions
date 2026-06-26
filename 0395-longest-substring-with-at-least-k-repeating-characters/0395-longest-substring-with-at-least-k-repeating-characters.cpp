class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;

        for(int c=1; c<=26; c++)
        {
            unordered_map<char, int> windowFreq;
            int left = 0;

            for(int i=0; i<s.size(); i++)
            {
                windowFreq[s[i]]++;

                while(windowFreq.size() > c)
                {
                    windowFreq[s[left]]--;
                    if(windowFreq[s[left]] == 0)
                    windowFreq.erase(s[left]);

                    left++;
                }

                

                if(windowFreq.size() == c)
                {
                    bool valid = true;

                    for(auto &it: windowFreq)
                    {
                        if(it.second < k)
                        {
                            valid = false;
                        }

                    }


                    if(valid)
                    ans = max(ans, i - left + 1);
                }
                
            }
        }


        return ans;
    }
};