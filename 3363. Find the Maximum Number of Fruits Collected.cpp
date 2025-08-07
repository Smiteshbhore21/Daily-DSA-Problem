class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        size_t n = fruits.size();
        vector<vector<int>> t(n, vector<int>(n, 0));
        int c1 = 0;
        for (int i = 0; i < n; i++) {
            c1 += fruits[i][i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j && i + j < n - 1) {
                    t[i][j] = 0;
                } else if (i > j && i + j < n - 1) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = fruits[i][j];
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                t[i][j] += max({t[i - 1][j - 1], t[i - 1][j],
                                (j + 1 < n) ? t[i - 1][j + 1] : 0});
            }
        }

        for (int j = 1; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                t[i][j] += max({t[i - 1][j - 1], t[i][j - 1],
                                (i + 1 < n) ? t[i + 1][j - 1] : 0});
            }
        }

        return c1 + t[n - 2][n - 1] + t[n - 1][n - 2];
    }
};

// DP(memoaization) -->
// class Solution {
// public:
//     size_t n = 0;
//     vector<vector<int>> t;
//     int maxCollectedFruits(vector<vector<int>>& fruits) {
//         n = fruits.size();
//         t.resize(n, vector<int>(n, -1));
//         int c1 = 0;
//         for (int i = 0; i < n; i++) {
//             c1 += fruits[i][i];
//         }
//         int c2 = child2Collect(0, n - 1, fruits);
//         int c3 = child3Collect(n - 1, 0, fruits);
//         return c1 + c2 + c3;
//     }
//     int child2Collect(int i, int j, vector<vector<int>>& fruits) {
//         if (i >= n || j < 0 || j >= n)
//             return 0;
//         if (i == n - 1 && j == n - 1)
//             return 0;
//         if (i == j || i > j)
//             return 0
//         if (t[i][j] != -1)
//             return t[i][j];
//         int bottomLeft = fruits[i][j] + child2Collect(i + 1, j - 1, fruits);
//         int bottomDown = fruits[i][j] + child2Collect(i + 1, j, fruits);
//         int bottomRight = fruits[i][j] + child2Collect(i + 1, j + 1, fruits);
//         return t[i][j] = max({bottomLeft, bottomDown, bottomRight});
//     }
//     int child3Collect(int i, int j, vector<vector<int>>& fruits) {
//         if (i >= n || j < 0 || j >= n)
//             return 0;
//         if (i == n - 1 && j == n - 1)
//             return 0;
//         if (i == j || i < j)
//             return 0;
//         if (t[i][j] != -1)
//             return t[i][j];
//         int upRight = fruits[i][j] + child3Collect(i - 1, j + 1, fruits);
//         int rightCell = fruits[i][j] + child3Collect(i, j + 1, fruits);
//         int bottomRight = fruits[i][j] + child3Collect(i + 1, j + 1, fruits);
//         return t[i][j] = max({upRight, rightCell, bottomRight});
//     }
// };
