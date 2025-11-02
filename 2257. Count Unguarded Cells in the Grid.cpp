class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (vector<int>& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        for (vector<int>& wall : walls) {
            grid[wall[0]][wall[1]] = -1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    markGuarded(i - 1, j, m, n, true, false, false, false,
                                grid);
                    markGuarded(i + 1, j, m, n, false, true, false, false,
                                grid);
                    markGuarded(i, j - 1, m, n, false, false, true, false,
                                grid);
                    markGuarded(i, j + 1, m, n, false, false, false, true,
                                grid);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    ans++;
            }
        }
        return ans;
    }

    bool isSafe(int row, int col, int& m, int& n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    void markGuarded(int row, int col, int& m, int& n, bool upper, bool lower,
                     bool left, bool right, vector<vector<int>>& grid) {
        if (!isSafe(row, col, m, n))
            return;
        if (grid[row][col] == 1 || grid[row][col] == -1)
            return;

        grid[row][col] = 2;
        
        if (upper) {
            markGuarded(row - 1, col, m, n, upper, lower, left, right, grid);
        } else if (lower) {
            markGuarded(row + 1, col, m, n, upper, lower, left, right, grid);
        } else if (right) {
            markGuarded(row, col + 1, m, n, upper, lower, left, right, grid);
        } else if (left) {
            markGuarded(row, col - 1, m, n, upper, lower, left, right, grid);
        }
        return;
    }
};
