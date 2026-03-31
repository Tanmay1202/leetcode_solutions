class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        vector<vector<pair<int, int>>> adj(n);

        for(auto &it: roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty())
        {
            auto [dis, node] = pq.top(); pq.pop();

            if(dis > dist[node]) continue;

            for(auto [next, cost] : adj[node])
            {
                if(cost + dis < dist[next])
                {
                    dist[next] = cost + dis;
                    pq.push({cost + dis, next});
                    ways[next] = ways[node];
                }
                else if(cost + dis == dist[next])
                {
                    ways[next] = (ways[next] + ways[node])%MOD;
                }
            }
        }

        if(dist[n-1] == LLONG_MAX)
        return 0;


        return ways[n-1];


    }
};