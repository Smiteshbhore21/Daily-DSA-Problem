class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int cnt = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string& s : strs) {
            int zeroCnt = 0, oneCnt = 0;
            for (const char& ch : s) {
                if (ch == '0')
                    zeroCnt++;
                else
                    oneCnt++;
            }
            for (int i = m; i >= zeroCnt; --i) {
                for (int j = n; j >= oneCnt; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroCnt][j - oneCnt] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
