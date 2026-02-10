class Solution {
private:
    // returns false if cycle found
    bool dfs(int node, vector<bool>& inPath, vector<bool>& visited, vector<int> adj[]) {
        visited[node] = true;
        inPath[node] = true;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                if (!dfs(neigh, inPath, visited, adj))
                    return false;
            }
            else if (inPath[neigh]) {
                return false; // cycle
            }
        }

        inPath[node] = false; // REQUIRED
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> adj[numCourses];
        vector<bool> visited(numCourses, false);
        vector<bool> inPath(numCourses, false);

        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]); // directed: b -> a
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, inPath, visited, adj))
                    return false; // cycle exists
            }
        }

        return true; // no cycle
    }
};
