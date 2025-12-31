class Solution {
public:
    const vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m;
    int n;
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m = row;
        n = col;

        int result = 0;
        int l = 0, r = cells.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canCross(cells, mid)) {
                result = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }

    bool canCross(vector<vector<int>>& cells, int mid) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i <= mid; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0 && dfs(0, j, grid))
                return true;
        }
        return false;
    }

    bool dfs(int row, int col, vector<vector<int>>& grid) {
        if (!isSafe(row, col)) {
            return false;
        }

        if (grid[row][col] == 1)
            return false;

        if (row == m - 1) {
            return true;
        }

        grid[row][col] = 1;
        for (const auto& d : directions) {
            int nr = row + d[0], nc = col + d[1];
            if (dfs(nr, nc, grid))
                return true;
        }

        return false;
    }

    bool isSafe(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};
