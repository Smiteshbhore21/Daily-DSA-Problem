class DSU {
public:
    vector<int> parent, unionBySize;
    DSU(int n) {
        parent.resize(n, 0);
        unionBySize.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionN(int node1, int node2) {
        int parent1 = findParent(node1);
        int parent2 = findParent(node2);

        if (parent1 == parent2)
            return;

        if (unionBySize[parent1] > unionBySize[parent2]) {
            parent[parent2] = parent1;
            unionBySize[parent1] += unionBySize[parent2];
        } else {
            parent[parent1] = parent2;
            unionBySize[parent2] += unionBySize[parent1];
        }
    }

    void reset(int x) {
        parent[x] = x;
        unionBySize[x] = 1;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        DSU dsu(n);
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        dsu.unionN(0, firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> people;

            int j = i;
            while (j < meetings.size() && meetings[j][2] == time) {
                dsu.unionN(meetings[j][0], meetings[j][1]);
                people.push_back(meetings[j][0]);
                people.push_back(meetings[j][1]);
                j++;
            }

            for (int p : people) {
                if (dsu.findParent(p) != dsu.findParent(0)) {
                    dsu.reset(p);
                }
            }

            i = j;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dsu.findParent(i) == dsu.findParent(0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
