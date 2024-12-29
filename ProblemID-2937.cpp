class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {
        int l=0;
        int cnt=0;
        while(l<s1.size() && l<s2.size() && l<s3.size() && s1[l]==s2[l] && s2[l]==s3[l])
        {
            cnt++;
            l++;
        }

        if(cnt==0)
        return -1;

        int totalOp = 0;
        totalOp += s1.size() - cnt;
        totalOp += s2.size() - cnt;
        totalOp += s3.size() - cnt;

        return totalOp;
        
    }

};