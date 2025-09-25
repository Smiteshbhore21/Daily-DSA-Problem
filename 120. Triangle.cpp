class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int row = 1; row < n; row++) {
            for (int col = 0; col <= row; col++) {
                triangle[row][col] =
                    triangle[row][col] +
                    min(triangle[row - 1][max(col - 1, 0)],
                        triangle[row - 1]
                                [min(col, (int)triangle[row - 1].size() - 1)]);
            }
        }
        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }
};

// Bottom Up (Optimized) -->
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<int> t = triangle[n - 1];
//         for (int row = n - 2; row >= 0; row--) {
//             for (int col = 0; col <= row; col++) {
//                 t[col] = triangle[row][col] + min(t[col], t[col + 1]);
//             }
//         }
//         return t[0];
//     }
// };

// Bottom Up -->
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> t = triangle;
//         for (int row = n - 2; row >= 0; row--) {
//             for (int col = 0; col <= row; col++) {
//                 t[row][col] =
//                     t[row][col] + min(t[row + 1][col], t[row + 1][col + 1]);
//             }
//         }
//         return t[0][0];
//     }
// };

// TLE -->
// class Solution {
// public:
//     int n = 0;
//     int t[201][201] = {{-1}};
//     int minimumTotal(vector<vector<int>>& triangle) {
//         n = triangle.size();
//         memset(t, -1, sizeof(t));
//         return solve(0, 0, triangle);
//     }
//     int solve(int level, int col, vector<vector<int>>& triangle) {
//         if (level == (n-1)) {
//             return triangle[level][col];
//         }
//         if (t[level][col] != -1) {
//             return t[level][col];
//         }
//         int minPathSum =
//             triangle[level][col] + min(solve(level + 1, col, triangle),
//                                        solve(level + 1, col + 1, triangle));
//         return t[level][col] =  minPathSum;
//     }
// };
