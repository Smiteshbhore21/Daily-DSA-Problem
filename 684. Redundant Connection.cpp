class Solution {
public:

    //DSU ->  Disjoint Set Union

    int totalNodes;
    vector<int> parent;
    vector<int> size;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        totalNodes = edges.size();
        for (int i = 0; i < totalNodes; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
        for (int i = 0; i < totalNodes; i++) {
            if (!unionBySize(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
        return edges[0];
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    bool unionBySize(int node1, int node2) {
        int parent1 = findParent(node1);
        int parent2 = findParent(node2);
        if (parent1 == parent2)
            return false;
        if (size[parent1] > size[parent2]) {
            size[parent1] += size[parent2];
            parent[parent2] = parent1;
        } else {
            size[parent2] += size[parent1];
            parent[parent1] = parent2;
        }
        return true;
    }
};
