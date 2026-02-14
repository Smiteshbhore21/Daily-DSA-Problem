class Solution {
public:
    double memo[101][101];
    double champagneTower(int poured, int query_row, int query_glass) {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                memo[i][j] = -1;
            }
        }
        return min(1.0, solve(poured, query_row, query_glass));
    }

    double solve(int poured, int i, int j) {
        if (i < 0 || j < 0 || i < j)
            return 0.0;

        if (i == 0 && j == 0)
            return poured;

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        double up_left = (solve(poured, i - 1, j - 1) - 1) / 2.0;
        double up_right = (solve(poured, i - 1, j) - 1) / 2.0;

        if (up_right < 0)
            up_right = 0.0;
        if (up_left < 0)
            up_left = 0.0;

        return memo[i][j] = up_right + up_left;
    }
};
