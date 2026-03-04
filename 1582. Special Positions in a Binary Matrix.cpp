class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<bool> isSpecialRows(m, false), isSpecialCols(n, false);
        for (int i = 0; i < m; i++) {
            int rowOnes = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    rowOnes++;
                if (rowOnes > 1)
                    break;
            }
            if (rowOnes == 1)
                isSpecialRows[i] = true;
        }

        for (int i = 0; i < n; i++) {
            int colOnes = 0;
            for (int j = 0; j < m; j++) {
                if (mat[j][i] == 1)
                    colOnes++;
                if (colOnes > 1)
                    break;
            }
            if (colOnes == 1)
                isSpecialCols[i] = true;
        }

        int result = 0;
        for (int i = 0; i < m; i++) {
            if (!isSpecialRows[i])
                continue;
            for (int j = 0; j < n; j++) {
                if (isSpecialCols[j] && mat[i][j] == 1) {
                    result++;
                }
            }
        }
        return result;
    }
};
