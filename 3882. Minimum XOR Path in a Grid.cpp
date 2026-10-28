class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>> memo;
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        return solve(0, 0, 0, grid);
    }

    int solve(int i, int j, int cost, vector<vector<int>>& grid) {
        cost ^= grid[i][j];
        if (i == m - 1 && j == n - 1) {
            return cost;
        }

        if (memo[i][j][cost] != -1)
            return memo[i][j][cost];

        int right = INT_MAX, down = INT_MAX;
        if (j + 1 < n)
            right = solve(i, j + 1, cost, grid);
        if (i + 1 < m)
            down = solve(i + 1, j, cost, grid);

        return memo[i][j][cost] = min(right, down);
    }
};
