class Solution {
public:
    void dfs(int node, int parent, vector<int>& subTreeXor, vector<int>& inTime,
             vector<int>& outTime, int& timer, vector<int>& nums,
             unordered_map<int, vector<int>>& adj) {
        subTreeXor[node] = nums[node];
        inTime[node] = timer;
        timer++;
        for (int& ngbr : adj[node]) {
            if (ngbr != parent) {
                dfs(ngbr, node, subTreeXor, inTime, outTime, timer, nums, adj);
                subTreeXor[node] ^= subTreeXor[ngbr];
            }
        }
        outTime[node] = timer;
        timer++;
    }

    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }

    int getScore(int a, int b, int c) {
        int maxXor = max({a, b, c});
        int minXor = min({a, b, c});

        return maxXor - minXor;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> subTreeXor(n, 0), inTime(n, 0), outTime(n, 0);
        int timer = 0;
        dfs(0, -1, subTreeXor, inTime, outTime, timer, nums, adj);
        int res = INT_MAX;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int xor1, xor2, xor3;
                if (isAncestor(u, v, inTime, outTime)) {
                    xor1 = subTreeXor[v];
                    xor2 = subTreeXor[u] ^ xor1;
                    xor3 = subTreeXor[0] ^ xor1 ^ xor2;
                } else if (isAncestor(v, u, inTime, outTime)) {
                    xor1 = subTreeXor[u];
                    xor2 = subTreeXor[v] ^ xor1;
                    xor3 = subTreeXor[0] ^ xor1 ^ xor2;
                } else {
                    xor1 = subTreeXor[u];
                    xor2 = subTreeXor[v];
                    xor3 = subTreeXor[0] ^ xor1 ^ xor2;
                }

                res = min(res, getScore(xor1, xor2, xor3));
            }
        }
        return res;
    }
};
