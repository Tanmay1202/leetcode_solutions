class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        int n = arr.size();
        if(n == 1)
            return 0;

        if(n == 2)
        {
            if(arr[0] > arr[1])
                return 0;
            else
                return 1;
        }

        int l = 0;
        int r = n - 1;

        while(l<r)
        {
            int m = l + (r-l)/2;

            if(arr[m] > arr[m+1])
            r = m;
            else
            l = m+1;
        }

        return l;

    }
};
