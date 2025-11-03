class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int groupMax = neededTime[0];
        int groupSum = neededTime[0];
        int ans = 0;

        for(int i=1; i<colors.size(); i++)
        {   
            if(colors[i] == colors[i-1])
            {
                groupSum += neededTime[i];
                groupMax = max(groupMax,neededTime[i]);
            }
            else
            {
                ans+= (groupSum - groupMax);
                groupSum = neededTime[i];
                groupMax = neededTime[i];
            }
        }

        ans += (groupSum - groupMax);



        return ans;
    }
};