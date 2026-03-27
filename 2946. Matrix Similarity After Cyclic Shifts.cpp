class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                } else {
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                }
            }
        }

        return true;
    }
};

// Time -> O(k * m * n) -->
// Space -> O(m * n) -->
// class Solution {
// public:
//     bool areSimilar(vector<vector<int>>& mat, int k) {
//         int n = mat[0].size(), m = mat.size();
//         vector<vector<int>> copy = mat;
//         while (k--) {
//             for (int i = 0; i < m; i++) {
//                 shift(mat[i], i % 2 == 0);
//             }
//         }
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] != copy[i][j])
//                     return false;
//             }
//         }
//         return true;
//     }
//     void shift(vector<int>& vec, bool even) {
//         int n = vec.size();
//         if (even) {
//             int prev = vec[0];
//             for (int i = n - 1; i >= 0; i--) {
//                 int curr = vec[i];
//                 vec[i] = prev;
//                 prev = curr;
//             }
//         } else {
//             int prev = vec[n - 1];
//             for (int i = 0; i < n; i++) {
//                 int curr = vec[i];
//                 vec[i] = prev;
//                 prev = curr;
//             }
//         }
//     }
// };
