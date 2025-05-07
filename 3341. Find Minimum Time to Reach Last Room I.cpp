class Solution {
    using p = pair<int, pair<int, int>>;

public:
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;

            pq.pop();
            if (i == m - 1 && j == n - 1) {
                return currTime;
            }

            for (auto& dir : dirs) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    int wait = max(moveTime[i_][j_] - currTime, 0);
                    int newTime = currTime + wait + 1;
                    if (result[i_][j_] > newTime) {
                        result[i_][j_] = newTime;
                        pq.push({newTime, {i_, j_}});
                    }
                }
            }
        }
        return -1;
    }
};
