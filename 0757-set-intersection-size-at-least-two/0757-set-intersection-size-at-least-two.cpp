class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<int> chosen;

        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[1] == b[1]) return a[0] > b[0];
                return a[1] < b[1];
            });

        int p2 = intervals[0][1];
        int p1 = p2 - 1;

        chosen.push_back(p1);
        chosen.push_back(p2);

        for (int i = 1; i < intervals.size(); i++) {

            // both inside
            if ((p1 >= intervals[i][0] && p1 <= intervals[i][1]) &&
                (p2 >= intervals[i][0] && p2 <= intervals[i][1]))
                continue;

            // only p2 inside
            if (! (p1 >= intervals[i][0] && p1 <= intervals[i][1]) &&
                  (p2 >= intervals[i][0] && p2 <= intervals[i][1])) {

                p1 = p2;
                p2 = intervals[i][1];
                chosen.push_back(p2);
                continue;
            }

            // none inside
            p2 = intervals[i][1];
            p1 = p2 - 1;
            chosen.push_back(p1);
            chosen.push_back(p2);
        }

        return chosen.size();
    }
};
