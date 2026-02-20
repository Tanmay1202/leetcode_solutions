class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, vector<int> &color)
    {
        for(int v=0; v<graph[u].size(); v++)
        {
            int i = graph[u][v];
            if(color[i] == -1)
            {
                color[i] = 1 - color[u];

                if(!dfs(graph, i, color))
                return false;
            }
            else if(color[i] == color[u])
            return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;

                if(!dfs(graph, i, color))
                return false;
            }
        }

        return true;
    }
};