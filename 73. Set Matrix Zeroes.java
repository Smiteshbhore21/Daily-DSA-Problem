class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean firstRowZero = false, firstColZero = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                firstRowZero = true;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != 0 &&
                    (matrix[0][j] == 0 || matrix[i][0] == 0)) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstColZero)
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        if (firstRowZero)
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
    }
}





//CPP ----->
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         bool firstRowZero = false, firstColZero = false;
//         for (int i = 0; i < m; i++) {
//             if (matrix[i][0] == 0) {
//                 firstColZero = true;
//                 break;
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             if (matrix[0][i] == 0) {
//                 firstRowZero = true;
//                 break;
//             }
//         }
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == 0) {
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//             }
//         }
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (matrix[i][j] != 0 &&
//                     (matrix[0][j] == 0 || matrix[i][0] == 0)) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         if (firstColZero)
//             for (int i = 0; i < m; i++) {
//                 matrix[i][0] = 0;
//             }
//         if (firstRowZero)
//             for (int i = 0; i < n; i++) {
//                 matrix[0][i] = 0;
//             }
//     }
// };
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         vector<int> row(m), col(n);
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == 0) {
//                     row[i] = 1;
//                     col[j] = 1;
//                 }
//             }
//         }
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (row[i] || col[j])
//                     matrix[i][j] = 0;
//             }
//         }
//     }
// };
