int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int& k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(k, 0)));

        // int dp[m + 1][n + 1][k + 1];
        // memset(dp, 0, sizeof(dp));

        for (int remain = 0; remain <= k - 1; remain++) {
            dp[m - 1][n - 1][remain] = ((remain + grid[m - 1][n - 1]) % k == 0);
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int remain = 0; remain <= k - 1; remain++) {
                    if (i == m - 1 && j == n - 1)
                        continue;

                    int R = (remain + grid[i][j]) % k;
                    int right = dp[i][j + 1][R];
                    int down = dp[i + 1][j][R];
                    dp[i][j][remain] = (right + down) % MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};

// class Solution {
// public:
//     int n = 0, m = 0, k = 0;
//     vector<vector<vector<int>>> t;
//     int numberOfPaths(vector<vector<int>>& grid, int k) {
//         m = grid.size();
//         n = grid[0].size();
//         this->k = k;
//         t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
//         return solve(0, 0, 0, grid);
//     }

//     int solve(int r, int c, int rem, vector<vector<int>>& grid) {
//         if (r >= m || c >= n)
//             return 0;

//         if (t[r][c][rem] != -1)
//             return t[r][c][rem];

//         if (r == m - 1 && c == n - 1)
//             return ((rem + grid[r][c]) % k == 0) ? 1 : 0;

//         int right = solve(r, c + 1, (rem + grid[r][c]) % k, grid);
//         int down = solve(r + 1, c, (rem + grid[r][c]) % k, grid);

//         return t[r][c][rem] = (down + right) % MOD;
//     }
// };
