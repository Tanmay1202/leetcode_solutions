class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        vector<int> devices(bank.size(), 0);
        int count = 0;

        for(int i=0; i<bank.size(); i++)
        {
            for(int j=0; j<bank[i].size(); j++)
            {
                if(bank[i][j] == '1')
                {
                    devices[i]++;
                }
            }
        }

        int prev = 0;

        for(int i=0; i<devices.size(); i++)
        {
            if(devices[i] == 0) continue;

            count += devices[i]*prev;
            prev = devices[i];
        }


        return count;
    }
};