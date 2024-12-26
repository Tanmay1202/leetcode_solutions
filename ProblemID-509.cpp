//RECURSIVE APPROACH
class Solution 
{
public:
    int fib(int n)
    {
        if(n<=1) return n;
        int last = fib(n-1);
        int s_last = fib(n-2);

        return last + s_last;
    }
};

//CLASSICAL APPROACH
class Solution {
public:
    int fib(int n)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        int a = 0;
        int b = 1;

        for(int i=2; i<=n; i++)
        {
            int temp = b;
            b = b + a;
            a = temp;
        }
        return b;
    }
};

