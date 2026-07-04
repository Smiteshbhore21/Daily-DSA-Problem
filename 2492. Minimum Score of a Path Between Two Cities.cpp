class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (vector<int>& road : roads) {
            int u = road[0];
            int v = road[1];
            int cost = road[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }

        vector<bool> visited(n + 1, false);

        int result = INT_MAX;

        dfs(1, visited, adj, result);

        return result;
    }

    void dfs(int u, vector<bool>& visited, vector<vector<pair<int, int>>>& adj,
             int& result) {

        visited[u] = true;

        for (auto& vec : adj[u]) {
            int v = vec.first;
            int dist = vec.second;
            result = min(result, dist);

            if (!visited[v]) {
                dfs(v, visited, adj, result);
            }
        }
    }
};
