class Solution {
public:
    int MOD = 1e9 + 7;
    int m;
    int n;

    vector<vector<array<int, 2>>> memo;

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memo.assign(m + 1, vector<array<int, 2>>(n, {-1, -1}));

        return solve(0, 0, 0, grid);
    }

    int solve(int i, int j, int cameFrom, vector<vector<int>>& grid) {
        if (i >= m || i < 0 || j >= n || j < 0)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (memo[i][j][cameFrom] != -1)
            return memo[i][j][cameFrom];

        int total = 0;
        if (grid[i][j] == 1) {
            if (cameFrom) {
                total = (total + solve(i, j + 1, 0, grid)) % MOD; // right --> 0
            } else {
                total = (total + solve(i + 1, j, 1, grid)) % MOD; // down --> 1
            }
        } else {
            total = (total + solve(i + 1, j, 1, grid)) % MOD; // down --> 1
            total = (total + solve(i, j + 1, 0, grid)) % MOD; // right --> 0
        }

        return memo[i][j][cameFrom] = total;
    }
};
