class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        // left, top, right, down
        int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    int sum = 0;
                    dfs(i, j, m, n, sum, grid);
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }

    void dfs(int r, int c, int& m, int& n, int& sum,
             vector<vector<int>>& grid) {
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 0) {
            sum += grid[r][c];
            grid[r][c] = 0;
            dfs(r + 1, c, m, n, sum, grid);
            dfs(r, c + 1, m, n, sum, grid);
            dfs(r - 1, c, m, n, sum, grid);
            dfs(r, c - 1, m, n, sum, grid);
        }
    }
};
