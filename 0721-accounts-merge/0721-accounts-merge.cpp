class Solution {
public:
    string find(string a,unordered_map<string, string> &parent)
    {
        if(parent[a] == a)
        return a;

        return parent[a] = find(parent[a], parent);
    }

    void unite(string a, string b, unordered_map<string, string> &parent, unordered_map<string, int> &rank)
    {
        string ra = find(a, parent);
        string rb = find(b, parent);

        if(rank[ra] < rank[rb])
        {
            parent[ra] = rb;
        }
        else if(rank[ra] > rank[rb])
        {
            parent[rb] = ra;
        }
        else
        {
            parent[ra] = rb;
            rank[rb]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        unordered_map<string, string> parent;
        unordered_map<string, int> rank;
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> groups;

        int n = accounts.size();

        for(int i=0; i<n; i++)
        {
            string name = accounts[i][0];
            //parent[accounts[i][1]] = accounts[i][1];  // initialize first email

            for(int j=1; j<accounts[i].size(); j++)
            {
                emailToName[accounts[i][j]] = name;
                if(parent.find(accounts[i][j]) == parent.end())
                parent[accounts[i][j]] = accounts[i][j];  // only initialize if new
                unite(accounts[i][1], accounts[i][j], parent, rank);
            }
        }


        for(auto &[email, name]: emailToName)
        {
            string root = find(email, parent);
            groups[root].push_back(email);
        }


        vector<vector<string>> result;

        for(auto& [root, emails]: groups)
        {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[root]);
            result.push_back(emails);
        }

        return result;
    }
};