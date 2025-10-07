class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        unordered_map<int, queue<int>> nextRain;

        for(int i=0; i<rains.size(); i++)
        {
            if(rains[i] != 0)
            {
                nextRain[rains[i]].push(i);
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        set<int> full;
        vector<int> ans(rains.size());

        for(int i=0; i<rains.size(); i++)
        {
            if(rains[i] > 0)
            {
                int x = rains[i];
                nextRain[x].pop();

                if(full.count(x))
                return {};

                if(!nextRain[x].empty())
                {
                    minHeap.push({nextRain[x].front(), x});
                }

                ans[i] = -1;

                full.insert(x);
            }
            else
            {
                if(!minHeap.empty())
                {
                    auto [day, lake] = minHeap.top();
                    minHeap.pop();
                    full.erase(lake);
                    ans[i] = lake;
                }
                else
                {
                    ans[i] = 1;
                }

            }
        }


        return ans;
    }
};