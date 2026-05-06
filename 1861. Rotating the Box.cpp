class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> rotate(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotate[i][j] = boxGrid[j][i];
            }
        }
        for (vector<char>& vec : rotate) {
            reverse(vec.begin(), vec.end());
        }
        for (int j = 0; j < m; j++) {
            int spaceRow = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (rotate[i][j] == '*') {
                    spaceRow = i - 1;
                    continue;
                }

                if (rotate[i][j] == '#') {
                    rotate[i][j] = '.';
                    rotate[spaceRow][j] = '#';
                    spaceRow--;
                }
            }
        }
        return rotate;
    }
};

// O(M*N^2)
// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
//         int m = boxGrid.size();
//         int n = boxGrid[0].size();
//         vector<vector<char>> rotate(n, vector<char>(m));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 rotate[i][j] = boxGrid[j][i];
//             }
//         }
//         for (vector<char>& vec : rotate) {
//             reverse(vec.begin(), vec.end());
//         }
//         for (int j = 0; j < m; j++) {
//             for (int i = n - 1; i >= 0; i--) {
//                 if (rotate[i][j] == '.') {
//                     int stoneRow = -1;
//                     for (int k = i - 1; k >= 0; k--) {
//                         if (rotate[k][j] == '*')
//                             break;
//                         else if (rotate[k][j] == '#') {
//                             stoneRow = k;
//                             break;
//                         }
//                     }
//                     if (stoneRow != -1) {
//                         rotate[i][j] = '#';
//                         rotate[stoneRow][j] = '.';
//                     }
//                 }
//             }
//         }
//         return rotate;
//     }
// };
