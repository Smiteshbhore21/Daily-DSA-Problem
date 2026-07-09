class DSU {
public:
    vector<int> rank;
    vector<int> parent;

    DSU(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v) {
        int parent1 = find(u);
        int parent2 = find(v);

        if (parent1 == parent2)
            return;

        if (rank[parent1] < rank[parent2]) {
            parent[parent1] = parent2;
        } else if (rank[parent1] > rank[parent2]) {
            parent[parent2] = parent1;
        } else {
            parent[parent2] = parent1;
            rank[parent1]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        DSU dsu = DSU(n);

        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff)
                dsu.unionByRank(i, i + 1);
        }

        vector<bool> result;

        for (vector<int>& q : queries) {
            int p1 = dsu.find(q[0]);
            int p2 = dsu.find(q[1]);

            if (p1 == p2)
                result.push_back(true);
            else
                result.push_back(false);
        }

        return result;
    }
};
