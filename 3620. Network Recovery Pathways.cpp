class Solution {
public:
    bool check(int mid, int n, long long k,
               vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();

            pq.pop();

            if (d > k) {
                continue;
            }

            if (u == n - 1)
                return true;

            if (dist[u] < d)
                continue;

            for (auto& [v, wt] : adj[u]) {
                if (wt < mid)
                    continue;
                if (dist[v] > d + wt) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        int l = INT_MAX, r = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if (!online[u] || !online[v])
                continue;

            adj[u].push_back({v, cost});
            l = min(l, cost);
            r = max(r, cost);
        }

        long long result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, n, k, adj)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
