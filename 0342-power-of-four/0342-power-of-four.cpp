class Solution {
private:
    bool solve(int n)
    {
        if(n==1)
        return true;

        if(n%4 != 0)
        return false;

        return solve(n/4);
    }
public:
    bool isPowerOfFour(int n) 
    {
        if(n==0)
        return false;

        if(n == 1)
        return true;

        
        return solve(n);
    }
};