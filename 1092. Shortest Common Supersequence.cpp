class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp = longestCommonSubsequen(str1, str2);
        int n = dp.size(), m = dp[0].size(), i = n - 1, j = m - 1;
        string ans = "";
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;

            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            } else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<vector<int>> longestCommonSubsequen(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0] = 0;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else {
                    int case1 = dp[i - 1][j];
                    int case2 = dp[i][j - 1];
                    dp[i][j] = max(case1, case2);
                }
            }
        }
        return dp;
    }
};
