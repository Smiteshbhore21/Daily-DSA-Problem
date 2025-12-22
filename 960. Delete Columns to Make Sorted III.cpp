class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1);
        int LIS = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                bool check = true;
                for (int k = 0; k < n; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            LIS = max(LIS, dp[i]);
        }
        return m - LIS;
    }
};
