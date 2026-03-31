class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> dist(n+1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<vector<pair<int, int>>> adj(n+1);

        for(auto &it: times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            auto [dis, node] = pq.top(); pq.pop();

            if(dis > dist[node]) continue;

            for(int i=0; i<adj[node].size(); i++)
            {
                int next = adj[node][i].first;
                int cost = adj[node][i].second;

                if(cost + dis < dist[next])
                {
                    dist[next] = cost + dis;
                    pq.push({cost + dis, next});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());

        return ans == INT_MAX ? -1 : ans;
    }
};