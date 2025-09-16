class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;

        for (int x : nums) {
            st.push(x);
            while (st.size() > 1) {
                long long a = st.top(); st.pop();
                long long b = st.top();
                long long g = gcd(a, b);
                if (g == 1) { st.push(a); break; }
                st.pop();
                st.push(lcm(a, b));
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back((int)st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
