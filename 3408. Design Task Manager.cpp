class TaskManager {
public:
    // taskPrioMap : taskId -> prio, taskUserMap : taskId -> userId
    unordered_map<int, int> taskPrioMap, taskUserMap;
    // priority , taskId
    priority_queue<pair<int, int>> maxHeap;
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int>& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        // taskPrioMap : taskId -> prio
        taskPrioMap[taskId] = priority;
        // taskUserMap : taskId -> userId
        taskUserMap[taskId] = userId;
        // priority , taskId
        maxHeap.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        // taskPrioMap : taskId -> prio
        taskPrioMap[taskId] = newPriority;
        // priority , taskId
        maxHeap.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        taskPrioMap[taskId] = -1;
    }

    int execTop() {
        while(!maxHeap.empty()){
            auto [prio, taskId] = maxHeap.top();
            maxHeap.pop();
            if(prio == taskPrioMap[taskId]){
                taskPrioMap[taskId] = -1;
                return taskUserMap[taskId];
            }
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
