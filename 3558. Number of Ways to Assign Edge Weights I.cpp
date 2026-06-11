int MOD = 1e9 + 7;
class Solution {
public:
    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node,
                    int parent) {
        int depth = 0;

        for (int& ngbr : adj[node]) {
            if (ngbr == parent)
                continue;

            depth = max(depth, getMaxDepth(adj, ngbr, node) + 1);
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = getMaxDepth(adj, 1, -1);

        return binaryExpo(2, d - 1);
    }

    long long binaryExpo(int a, int b) {
        if (b == 0)
            return 1;

        long long half = binaryExpo(a, b / 2) % MOD;

        long long result = (half * half) % MOD;;

        if (b % 2 == 1)
            return (result * a) % MOD;

        return result;
    }
};
