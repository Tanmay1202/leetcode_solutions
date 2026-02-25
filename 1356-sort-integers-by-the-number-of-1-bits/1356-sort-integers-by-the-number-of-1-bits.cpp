class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        map<int, vector<int>> mpp;

        for(int x : arr)
        {
            mpp[__builtin_popcount(x)].push_back(x);
        }

        vector<int> ans;

        for(auto &it : mpp)
        {
            sort(it.second.begin(), it.second.end());

            for(int x : it.second)
                ans.push_back(x);
        }

        return ans;
    }
};