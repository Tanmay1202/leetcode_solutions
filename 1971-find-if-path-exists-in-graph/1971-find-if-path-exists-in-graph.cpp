class Solution {
public:
    bool ans = false;
    void dfs(int n, vector<vector<int>> &adj, int src, int dest, vector<bool> &vis)
    {
        if(src == dest) 
        {
            ans = true;
            return;
        }
        if(vis[src])
        return;

        vis[src] = true;

        for(auto it: adj[src])
        {
            if(!vis[it])
            {
                dfs(n, adj, it, dest, vis);
            }
        }



    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //vector<bool> vis(n, false);
        vector<vector<int>> adj(n);

        for(auto &it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);

        dfs(n, adj, source, destination, vis);

        return ans;



    }
};