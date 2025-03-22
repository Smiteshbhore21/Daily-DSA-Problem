
class DSU {
public:
    vector<int> parent, bySize;
    DSU(int n) {
        parent.resize(n);
        bySize.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            bySize[i] = 1;
        }
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        parent[node] = find(parent[node]);
        return parent[node];
    }

    void unionCom(int node1, int node2) {
        int rootParent1 = find(node1), rootParent2 = find(node2);

        if (rootParent1 == rootParent2)
            return;
        if (bySize[rootParent1] > bySize[rootParent2]) {
            parent[rootParent2] = rootParent1;
            bySize[rootParent1] += bySize[rootParent2];
        } else {
            parent[rootParent1] = rootParent2;
            bySize[rootParent2] += bySize[rootParent1];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> edgeCount;
        for (vector<int>& edge : edges) {
            dsu.unionCom(edge[0], edge[1]);
        }
        for (vector<int>& edge : edges) {
            int root = dsu.find(edge[0]);
            edgeCount[root]++;
        }

        int completeCount = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            if (dsu.find(vertex) == vertex) {
                int nodeCount = dsu.bySize[vertex];
                int expectedEdges = (nodeCount * (nodeCount - 1)) / 2;
                if (edgeCount[vertex] == expectedEdges)
                    completeCount++;
            }
        }
        return completeCount;
    }
};
