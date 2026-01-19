class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefixSum(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefixSum[i][j] =
                    (j == 0) ? mat[i][j] : prefixSum[i][j - 1] + mat[i][j];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                prefixSum[i][j] = (i == 0)
                                      ? prefixSum[i][j]
                                      : prefixSum[i - 1][j] + prefixSum[i][j];
            }
        }

        int low = 1, high = min(m, n), ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            bool found = false;

            for (int i = 0; i + mid - 1 < m && !found; i++) {
                for (int j = 0; j + mid - 1 < n; j++) {
                    int r2 = i + mid - 1;
                    int c2 = j + mid - 1;

                    int total = prefixSum[r2][c2];
                    if (i > 0)
                        total -= prefixSum[i - 1][c2];
                    if (j > 0)
                        total -= prefixSum[r2][j - 1];
                    if (i > 0 && j > 0)
                        total += prefixSum[i - 1][j - 1];

                    if (total <= threshold) {
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
