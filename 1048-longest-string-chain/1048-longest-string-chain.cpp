class Solution {
private:
    bool validate(string a, string b) {
        if (a.size() + 1 != b.size())
            return false;

        int i=0, j=0;
        bool skipped = false;

        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                if(skipped) return false;
                skipped = true;
                j++;
            }
        }

        return true;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        sort(words.begin(), words.end(),
        [](const string &a, const string &b){
            return a.size() < b.size();
        });


        for(int i=n-1; i>=0; i--)
        {
            for(int j=i-1; j>=-1; j--)
            {
                int skip = dp[i+1][j+1];

                int take = 0;
                
                if(j == -1 || validate(words[j], words[i]))
                {
                    take = 1 + dp[i+1][i+1];
                }


                dp[i][j+1] = max(skip, take);
            }
        }


        return dp[0][0];
    }
};