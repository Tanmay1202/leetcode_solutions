class Solution {
public:
    vector<int> parent;
    int findParent(int node)
    {
        if(node == parent[node])
        return node;

        return parent[node] = findParent(parent[node]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();

        if(cables < n-1) return -1;

        parent.resize(n);
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        int extra = 0;
        for(auto it: connections)
        {
            int u = findParent(it[0]);
            int v = findParent(it[1]);

            if(u == v)
            extra++;
            else
            {
                parent[v] = u;
            }
        }

        int components = 0;

        for(int i=0; i<n; i++)
        {
            if(parent[i] == i)
            {
                components++;
            }
        }

        int needed = components - 1;

        if(extra < needed) return -1;

        return needed;

    }
};