class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size();
        int negcnt = 0;
        int minAbs = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int posNum = abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    negcnt++;
                }
                minAbs = min(minAbs, posNum);
                sum += posNum;
            }
        }
        if (negcnt % 2 == 1) {
            return sum - 2 * minAbs;
        }
        return sum;
    }
};
