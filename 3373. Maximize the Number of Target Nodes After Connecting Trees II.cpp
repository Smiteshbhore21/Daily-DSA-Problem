class Solution {
public:
    int bfs(int start, const vector<vector<int>>& adj,
            vector<bool>* included = nullptr) {
        queue<pair<int, int>> q;
        q.push({start, -1});
        int count = 0, level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (level % 2 == 0)
                count += size;
            while (size--) {
                auto [curr, parent] = q.front();
                q.pop();
                if (included && level % 2 == 0)
                    (*included)[curr] = true;
                for (int v : adj[curr]) {
                    if (v == parent)
                        continue;
                    q.push({v, curr});
                }
            }
            ++level;
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<vector<int>> adj1(n1), adj2(n2);
        for (vector<int>& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (vector<int>& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        int evenCount2 = bfs(0, adj2), oddCount2 = n2 - evenCount2;
        int best2 = max(evenCount2 ,oddCount2);
        vector<bool> included(n1, false);
        int evenCount1 = bfs(0, adj1, &included);
        vector<int> ans(n1);
        for (int i = 0; i < n1; i++) {
            if (included[i]) {
                ans[i] = evenCount1 + best2;
            } else {
                ans[i] = n1 - evenCount1 + best2;
            }
        }
        return ans;
    }
};
