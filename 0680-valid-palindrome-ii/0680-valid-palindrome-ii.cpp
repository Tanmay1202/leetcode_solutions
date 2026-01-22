class Solution {
public:
    bool val(string s, int left, int high)
    {
        while(left < high)
        {
            if(s[left] != s[high]) return false;

            left++;
            high--;
        }

        return true;
    }
    bool validPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left <= right)
        {

            if(s[left] != s[right])
            {
                return val(s, left+1, right) || val(s, left, right - 1);
            }

            left++;
            right--;
        }

        return true;
        
    }
};