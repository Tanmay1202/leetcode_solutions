class Solution {
private:
    void dfs(int u, vector<vector<int>>& isConnected, vector<bool> &visited, int n)
    {
        if(visited[u]) return;
        visited[u] = true;

        for(int i=0; i<n; i++)
        {
            if(isConnected[u][i] == 1 && !visited[i])
            dfs(i, isConnected, visited, n);
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //int count = 0;
        int n = isConnected.size();
        vector<bool> visited(n);
        int count = 0;

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(i, isConnected, visited, n);
                count++;
            }
        }

        return count;
    }
};