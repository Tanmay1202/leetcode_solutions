class Solution {
public:
    bool cycle = false;
    void dfs(int u, vector<int> &visited, vector<vector<int>> adj, vector<int> &ans)
    {
        visited[u] = 1;

        for(int i=0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]] == 0)
            {
                dfs(adj[u][i], visited, adj, ans);
                if(cycle) return;
            }
            else if(visited[adj[u][i]] == 1)
            {
                cycle = true;
                return;
            }
        }

        visited[u] = 2;
        ans.push_back(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& req) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);

        vector<int> ans;
        
        for(auto &it: req)
        {
            adj[it[1]].push_back(it[0]);
        }


        for(int i=0; i<numCourses; i++)
        {
            if(visited[i] == 0)
            {
                dfs(i, visited, adj, ans);
                if(cycle)
                return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};