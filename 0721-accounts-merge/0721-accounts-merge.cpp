class Solution {
public:
    unordered_map<string, unordered_set<string>> graph;
    unordered_map<string, string> emailToName;
    unordered_set<string> visited;

    void dfs(const string &email, vector<string>& component)
    {
        visited.insert(email);
        component.push_back(email);

        for(auto &neighbour: graph[email])
        {
            if(!visited.count(neighbour))
            {
                dfs(neighbour, component);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) 
    {
        vector<vector<string>> ans;
        //vector<string> visited;

        int n = acc.size();

        for(int i=0; i<n; i++)
        {
            string key = acc[i][0];
            for(int j=1; j<acc[i].size(); j++)
            {
                emailToName[acc[i][j]] = key;
                graph[acc[i][j]].insert(acc[i][1]);
                graph[acc[i][1]].insert(acc[i][j]);
            }
        }

        for(auto & [email, name] : emailToName)
        {
            if(!visited.count(email))
            {
                vector<string> component;
                dfs(email, component);
                sort(component.begin(), component.end());
                component.insert(component.begin(), name);
                ans.push_back(component);
            }
        }


        return ans;
    }
};