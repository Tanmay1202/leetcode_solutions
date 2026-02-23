class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> topo;
        vector<int> inDegree(numCourses);

        for(auto it: pre)
        {
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<numCourses; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                inDegree[adj[i][j]]++;
            }
        }


        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i] == 0)
            q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int i=0; i<adj[node].size(); i++)
            {
                inDegree[adj[node][i]]--;

                if(inDegree[adj[node][i]] == 0)
                q.push(adj[node][i]);
            }
        }

        if(numCourses != topo.size())
        return {};

        return topo;
    }
};