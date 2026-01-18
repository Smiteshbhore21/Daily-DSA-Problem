class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> colPrefixSum(m, vector<int>(n, 0)),
            rowPrefixSum(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowPrefixSum[i][j] =
                    grid[i][j] + (j > 0 ? rowPrefixSum[i][j - 1] : 0);
                colPrefixSum[i][j] =
                    grid[i][j] + (i > 0 ? colPrefixSum[i - 1][j] : 0);
            }
        }

        int maxSide = min(m, n);

        for (int side = maxSide; side >= 2; side--) {

            for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {
                    int targetSum = rowPrefixSum[i][j + side - 1] -
                                    (j > 0 ? rowPrefixSum[i][j - 1] : 0);

                    bool allSame = true;
                    for (int r = i + 1; r < i + side; r++) {
                        int rowSum = rowPrefixSum[r][j + side - 1] -
                                     (j > 0 ? rowPrefixSum[r][j - 1] : 0);

                        if (targetSum != rowSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if (!allSame) {
                        continue;
                    }

                    for (int c = j; c < j + side; c++) {
                        int colSum = colPrefixSum[i + side - 1][c] -
                                     (i > 0 ? colPrefixSum[i - 1][c] : 0);

                        if (targetSum != colSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if (!allSame) {
                        continue;
                    }

                    int diag = 0;
                    int antidiag = 0;
                    for (int k = 0; k < side; k++) {
                        diag += grid[i + k][j + k];
                        antidiag += grid[i + k][j + side - 1 - k];
                    }
                    if (diag == targetSum && antidiag == targetSum) {
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};
