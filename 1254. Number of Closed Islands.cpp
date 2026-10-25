class Solution {
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int m;
    int n;

    vector<vector<bool>> visited;

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    result += (dfs(i, j, grid));
                }
            }
        }

        return result;
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i >= m || i < 0 || j >= n || j < 0)
            return 0;

        if (visited[i][j])
            return 1;

        visited[i][j] = true;

        if (grid[i][j] == 1)
            return 1;

        int res = 1;
        for (auto d : dir) {
            int _i = i + d[0];
            int _j = j + d[1];

            int temp = dfs(_i, _j, grid);
            res = res & temp;
        }

        return res;
    }
};
