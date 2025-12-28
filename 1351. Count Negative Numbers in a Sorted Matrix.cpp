// O(n + m) -->
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int negCnt = 0;

        int row = m - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            if (grid[row][col] >= 0) {
                col++;
            } else {
                negCnt += (n - col);
                row--;
            }
        }

        return negCnt;
    }
};

// O(m * log(n)) -->
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int negCnt = 0;
//         for (int i = 0; i < m; i++) {
//             int l = 0, r = n - 1;
//             int firstNeg = n;
//             while (l <= r) {
//                 int mid = l + (r - l) / 2;
//                 if (grid[i][mid] >= 0) {
//                     l = mid + 1;
//                 } else {
//                     firstNeg = mid;
//                     r = mid - 1;
//                 }
//             }
//             negCnt += (n - firstNeg);
//         }
//         return negCnt;
//     }
// };

// O(m * n) -->
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int negCnt = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = n - 1; j >= 0; j--) {
//                 if (grid[i][j] >= 0)
//                     break;
//                 negCnt++;
//             }
//         }
//         return negCnt;
//     }
// };
