class TaskManager {
public:
    // Max-heap storing {priority, taskId}
    priority_queue<pair<int,int>> pq;

    // taskId -> userId
    unordered_map<int,int> user;

    // taskId -> current priority
    unordered_map<int,int> cur;

    TaskManager(vector<vector<int>>& tasks) {
        for (const auto &t : tasks) {
            int u = t[0], id = t[1], p = t[2];
            pq.emplace(p, id);
            user[id] = u;
            cur[id]  = p;
        }
    }
    
    void add(int userId, int taskId, int priority) 
    {
        pq.emplace(priority, taskId);
        user[taskId] = userId;
        cur[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) 
    {
        cur[taskId] = newPriority;
        pq.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) 
    {
        user.erase(taskId);
        cur.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty())
        {
            auto [p, id] = pq.top();

            if(cur.count(id) && cur[id] == p)
            {
                int u = user[id];
                cur.erase(id);
                user.erase(id);
                pq.pop();
                return u;
            }

            pq.pop();
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */