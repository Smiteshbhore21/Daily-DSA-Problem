class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        vector<vector<pair<int,int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int node = q.top().second;
            int d = q.top().first;
            q.pop();
            if (d > dist[node]) {
                continue;
            }
            for (auto& it : adj[node]) {
                int ne = it.first;
                int wt = it.second;
                if (dist[ne] > dist[node] + wt) {
                    dist[ne] = dist[node] + wt;
                    q.push({dist[ne], ne});
                }
            }
        }
        return dist[n - 1] == 1e9 ? -1 : dist[n - 1];
    }
};
