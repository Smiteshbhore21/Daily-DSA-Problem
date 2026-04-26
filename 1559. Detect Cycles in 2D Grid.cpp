class Solution {
public:
    int m, n;
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && dfs(i, j, i, j, grid, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int j, int prev_i, int prev_j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        if (visited[i][j])
            return true;

        visited[i][j] = true;

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                grid[i][j] == grid[new_i][new_j]) {
                if (new_i == prev_i && new_j == prev_j)
                    continue;
                if (dfs(new_i, new_j, i, j, grid, visited))
                    return true;
            }
        }
        return false;
    }
};
