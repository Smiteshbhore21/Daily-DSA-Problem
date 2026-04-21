class DSU {
    int[] parent;
    int[] rank;

    public DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    public void union(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);

        if (p1 == p2)
            return;

        if (rank[p1] == rank[p2]) {
            rank[p2]++;
            parent[p1] = p2;
        } else if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
        }
    }
}

class Solution {
    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        DSU dsu = new DSU(n);

        for (int[] swap : allowedSwaps) {
            dsu.union(swap[0], swap[1]);
        }

        HashMap<Integer, HashMap<Integer, Integer>> groupFreq = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int curr = source[i];

            int parent = dsu.find(i);

            groupFreq.putIfAbsent(parent, new HashMap<>());
            groupFreq.get(parent).put(curr,
                    groupFreq.get(parent).getOrDefault(curr, 0) + 1);
        }

        int hammingDistance = 0;
        for (int i = 0; i < n; i++) {
            int parent = dsu.find(i);

            if (groupFreq.get(parent).getOrDefault(target[i], 0) > 0) {
                groupFreq.get(parent).put(target[i], groupFreq.get(parent).get(target[i]) - 1);
            } else {
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
}
