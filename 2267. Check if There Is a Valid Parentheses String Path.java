class Solution {
    int n;
    int m;

    int[][][] memo;

    public boolean hasValidPath(char[][] grid) {
        m = grid.length;
        n = grid[0].length;

        if ((m + n - 1 % 2) == 1)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        memo = new int[101][101][201];
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                Arrays.fill(memo[i][j], -1);
            }
        }

        return solve(0, 0, 0, grid);
    }

    boolean solve(int i, int j, int openCount, char[][] grid) {
        if (grid[i][j] == '(')
            openCount += 1;
        else
            openCount -= 1;

        if (openCount < 0) {
            return false;
        }

        if (memo[i][j][openCount] != -1)
            return memo[i][j][openCount] == 1;

        if (i == m - 1 && j == n - 1) {
            return (openCount == 0);
        }

        if (isValid(i + 1, j)) {
            if (solve(i + 1, j, openCount, grid)) {
                memo[i][j][openCount] = 1;
                return true;
            }
        }
        if (isValid(i, j + 1)) {
            if (solve(i, j + 1, openCount, grid)) {
                memo[i][j][openCount] = 1;
                return true;
            }
        }

        memo[i][j][openCount] = 0;
        return false;
    }

    boolean isValid(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
}
