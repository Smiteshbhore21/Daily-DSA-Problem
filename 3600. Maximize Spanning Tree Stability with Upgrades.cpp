class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n, 0), rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    bool unionNodes(int node1, int node2) {
        int parentNode1 = find(node1);
        int parentNode2 = find(node2);

        if (parentNode1 == parentNode2)
            return false;

        if (rank[parentNode1] > rank[parentNode2])
            parent[parentNode2] = parentNode1;
        else if (rank[parentNode1] < rank[parentNode2])
            parent[parentNode1] = parentNode2;
        else {
            parent[parentNode1] = parentNode2;
            rank[parentNode2]++;
        }

        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if (m == 1) {
                if (dsu.find(u) == dsu.find(v))
                    return -1;
                dsu.unionNodes(u, v);
            }
        }

        int result = -1;
        int l = 1;
        int r = 2 * 1e5;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(n, edges, k, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }

    bool check(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);

        vector<vector<int>> upgradeCandidates;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if (m == 1) {
                if (s < mid)
                    return false;

                dsu.unionNodes(u, v);
            } else {
                if (s >= mid) {
                    // no need to upgrade
                    dsu.unionNodes(u, v);
                } else if (2 * s >= mid) {
                    upgradeCandidates.push_back({u, v});
                }
            }
        }

        for (auto& edge : upgradeCandidates) {
            int u = edge[0];
            int v = edge[1];

            if (dsu.find(u) != dsu.find(v)) {
                if (k <= 0)
                    return false;
                dsu.unionNodes(u, v);
                k--;
            }
        }

        int root = dsu.find(0);
        for(int node = 1; node <= n - 1; node++){
            if (dsu.find(node) != root) {
                return false;
            }
        }
        return true;
    }
};
