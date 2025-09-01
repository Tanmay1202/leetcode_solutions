class Solution {
private:
    double gain(int p, int t) {
        return (double)(p + 1) / (t + 1) - (double)p / t;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;

        // build heap with initial gains
        for (auto &c : classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), {p, t}});
        }

        // assign extra students
        while (extraStudents--) {
            auto top = pq.top(); 
            pq.pop();

            int p = top.second.first;
            int t = top.second.second;

            p++; 
            t++;

            pq.push({gain(p, t), {p, t}});
        }

        // compute final average
        double sum = 0.0;
        while (!pq.empty()) {
            auto curr = pq.top(); 
            pq.pop();
            int p = curr.second.first;
            int t = curr.second.second;
            sum += (double)p / t;
        }

        return sum / classes.size();
    }
};