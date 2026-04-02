class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> dist(n, 0.0);
        dist[start] = 1.0;


        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start});

        while(!pq.empty())
        {
            auto [p, node] = pq.top(); pq.pop();
            for(auto [v, w]: adj[node])
            {
                if(p*w > dist[v])
                {
                    dist[v] = p*w;
                    pq.push({p*w, v});
                }
            }
        }

        return dist[end];
        
    }
};