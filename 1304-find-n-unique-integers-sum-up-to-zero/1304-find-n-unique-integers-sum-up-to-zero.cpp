class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int> result;

        int i = -(n/2);

        while (i <= n/2)
        {
            if (i == 0)  
            {
                i++;
                continue;
            }

            result.push_back(i);
            i++;
        }

        if (n % 2 != 0)
            result.push_back(0);

        return result;
    }
};
