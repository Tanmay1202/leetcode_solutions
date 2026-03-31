class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        vector<vector<pair<int, int>>> adj(n);

        for(auto &flight: flights)
        {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        int stops = 0;

        queue<pair<int, int>> q;

        q.push({src, 0});

        while(!q.empty() && stops <= k)
        {
            int sz = q.size();
            vector<int> temp = dist;

            for(int i=0; i<sz; i++)
            {
                auto [node, cost] = q.front();
                q.pop();

                

                for(int i=0; i<adj[node].size(); i++)
                {
                    int next = adj[node][i].first;
                    int price = adj[node][i].second;

                    if(price + cost < temp[next])
                    {
                        temp[next] = cost + price;

                        q.push({next, price + cost});
                    }
                }
            }

            stops++;
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};