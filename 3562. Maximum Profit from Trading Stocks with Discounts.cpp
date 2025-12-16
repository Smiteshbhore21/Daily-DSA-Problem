class Solution {
public:
    vector<int> present, future;
    vector<vector<int>> tree;
    int budget;
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        tree.assign(n, vector<int>());
        this->present = present;
        this->future = future;
        this->budget = budget;
        for (vector<int>& h : hierarchy) {
            tree[h[0] - 1].push_back(h[1] - 1);
        }
        vector<vector<int>> dp = dfs(0);
        return dp[budget][0];
    }

    vector<vector<int>> dfs(int u) {
        vector<vector<int>> dp(budget + 1, vector<int>(2, 0));
        for (int v : tree[u]) {
            vector<vector<int>> child = dfs(v);
            vector<vector<int>> next(budget + 1, vector<int>(2, 0));
            for (int b = 0; b <= budget; b++) {
                for (int cb = 0; cb <= b; cb++) {
                    next[b][0] = max(next[b][0], dp[b - cb][0] + child[cb][0]);
                    next[b][1] = max(next[b][1], dp[b - cb][1] + child[cb][1]);
                }
            }
            dp = next;
        }
        vector<vector<int>> ans(budget + 1, vector<int>(2, 0));
        for (int b = 0; b <= budget; b++) {
            ans[b][0] = dp[b][0];
            if (b >= present[u]) {
                ans[b][0] = max(ans[b][0],
                                future[u] - present[u] + dp[b - present[u]][1]);
            }
            int discount = present[u] / 2;
            ans[b][1] = dp[b][0];
            if (b >= discount) {
                ans[b][1] = max(ans[b][1],
                                future[u] - discount + dp[b - discount][1]);
            }
        }
        return ans;
    }
};
