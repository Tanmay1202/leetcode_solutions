class Solution {
public:
    int ladderLength(string beginWord, string endWord,vector<string>& wordList)
    {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord))
            return 0;

        q.push(beginWord);
        int count = 1;

        while (!q.empty()) 
        {
            int size = q.size();

            for (int i = 0; i < size; i++) 
            {
                string str = q.front();
                q.pop();

                if(str == endWord) return count;

                for (int i = 0; i < str.size(); i++) 
                {
                    string test = str;
                    for(char ch = 'a'; ch <= 'z'; ch++) 
                    {
                        test[i] = ch;
                        if (st.count(test)) 
                        {
                            q.push(test);
                            st.erase(test);
                        }
                    }
                }
            }

            count++;
        }

        return 0;
    }
};