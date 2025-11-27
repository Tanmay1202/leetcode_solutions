class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int j = 0;
        int i=0;

        while(i < s.size() && j < g.size())
        {
            if(s[i] >= g[j])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }


        return count;
    }
};