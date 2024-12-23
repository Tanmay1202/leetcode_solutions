class Solution {
public:
    bool isPalindrome(int x) 
    {
        int original = x;
        long long int rev;
        while(x!=0)
        {
            int digit = x%10;
            rev = rev*10 + digit;
            x = x/10;
        }

        if(rev > INT_MAX || rev < INT_MIN){
            return false;
        }

        if(original<0)
        {
            return false;
        }

        if(original != rev)
        {
            return false;
        }
        
        return true;
    }
};
