class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = colors.size();
        vector<int> indegree(n, 0);

        for (auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            indegree[vec[1]]++;
        }

        queue<int> que;
        vector<vector<int>> t(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = 0;
        int countNode = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            countNode++;
            ans = max(ans, t[u][colors[u] - 'a']);

            for (int& v : adj[u]) {
                for (int i = 0; i < 26; i++) {
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));
                }
                indegree[v]--;
                if (indegree[v] == 0)
                    que.push(v);
            }
        }
        if(countNode < n)
            return -1;
        return ans;
    }
};
