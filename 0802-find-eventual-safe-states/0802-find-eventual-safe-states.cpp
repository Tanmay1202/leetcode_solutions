class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<vector<int>> rev(V);
        vector<int> inDegree(V, 0);

        // Reverse graph
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                rev[graph[i][j]].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;

        // Original terminal nodes
        for(int i = 0; i < V; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int i = 0; i < rev[node].size(); i++)
            {
                inDegree[rev[node][i]]--;

                if(inDegree[rev[node][i]] == 0)
                    q.push(rev[node][i]);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};