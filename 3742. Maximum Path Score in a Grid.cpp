class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> memo;
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        memo = vector<vector<vector<int>>>(
            m, vector<vector<int>>(n, vector<int>(k + 1, -2)));

        int startCost = (grid[0][0] == 0 ? 0 : 1);
        if (startCost > k)
            return -1;

        return solve(0, 0, grid, k - startCost);
    }

    int solve(int i, int j, vector<vector<int>>& grid, int k) {
        if (k < 0)
            return -1;

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (memo[i][j][k] != -2)
            return memo[i][j][k];

        int right = -1, down = -1;

        // Right
        if (j + 1 < n) {
            int cost = grid[i][j + 1] != 0 ? 1 : 0;
            int next = solve(i, j + 1, grid, k - cost);
            if (next != -1)
                right = grid[i][j] + next;
        }

        // Down
        if (i + 1 < m) {
            int cost = grid[i + 1][j] != 0 ? 1 : 0;
            int next = solve(i + 1, j, grid, k - cost);
            if (next != -1)
                down = grid[i][j] + next;
        }

        return memo[i][j][k] = max(right, down);
    }
};
