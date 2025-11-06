class DSU {
public:
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int node1, int node2) {
        int node1P = findParent(node1);
        int node2P = findParent(node2);

        if (node1P == node2P)
            return;

        if (sz[node2P] > sz[node1P]) {
            parent[node1P] = node2P;
            sz[node2P] += sz[node1P];
        } else {
            parent[node2P] = node1P;
            sz[node1P] += sz[node2P];
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU dsu(c);

        for (const auto& c : connections) {
            dsu.unionBySize(c[0], c[1]);
        }

        vector<set<int>> stations(c + 1);
        for (int i = 1; i <= c; i++) {
            int r = dsu.findParent(i);
            stations[r].insert(i);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int q1 = q[0];
            int q2 = q[1];
            int r = dsu.findParent(q2);
            if (q1 == 1) {
                if (stations[r].count(q2)) {
                    ans.push_back(q2);
                } else {
                    if (stations[r].empty())
                        ans.push_back(-1);
                    else
                        ans.push_back(*stations[r].begin());
                }
            } else {
                stations[r].erase(q2);
            }
        }
        return ans;
    }
};
