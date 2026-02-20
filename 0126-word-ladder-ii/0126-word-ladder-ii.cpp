class Solution {
private:
    void dfs(unordered_map<string, vector<string>>& parent, vector<vector<string>>& result, vector<string>& inter, string beginWord, string curr) 
    {
        inter.push_back(curr);
        if (curr == beginWord) {
            vector<string> temp = inter;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            inter.pop_back();
            return;
        }

        for (int i = 0; i < parent[curr].size(); i++) {
            dfs(parent, result, inter, beginWord, parent[curr][i]);
        }

        inter.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> level;
        unordered_map<string, vector<string>> parent;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(!dict.count(endWord)) return {};

        queue<string> q;
        bool found = false;

        level[beginWord] = 1;

        q.push(beginWord);

        while (!q.empty() && !found) {
            int sz = q.size();

            unordered_set<string> used;

            for (int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.size(); j++) {
                    string test = word;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        test[j] = ch;
                        if (dict.count(test)) {
                            if (level.find(test) == level.end()) {
                                level[test] = level[word] + 1;
                                parent[test].push_back(word);
                                q.push(test);
                            } else if (level[test] == level[word] + 1) {
                                parent[test].push_back(word);
                            }

                            used.insert(test);
                        }

                        if (test == endWord)
                            found = true;
                    }
                }
            }

            for(auto &it: used)
            {
                dict.erase(it);
            }
        }

        vector<vector<string>> result;
        vector<string> inter;

        dfs(parent, result, inter, beginWord, endWord);

        return result;
    }
};