class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for(int i=0; i<ast.size(); i++)
        {
            int curr = ast[i];
            bool alive = true;
            while(!st.empty() && st.top() > 0 && ast[i] < 0)
            {
                //int max = INT_MIN;
                if(abs(curr) > st.top())
                {
                    st.pop();
                }
                else if(abs(curr) == st.top())
                {
                    st.pop();
                    alive = false;
                    break;
                }
                else
                {
                    alive = false;
                    break;
                }
            }

            if(alive)
            st.push(curr);
        }

        vector<int> result(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;


    }
};