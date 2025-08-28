// Using Map
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(grid[i][j]);
            }
        }

        for (auto& it : mp) {
            if (it.first >= 0) {
                sort(it.second.begin(), it.second.end());
            } else {
                sort(it.second.rbegin(), it.second.rend());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return grid;
    }
};

// Straight Forward -->
// class Solution {
// public:
//     int n = 0;

//     void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc) {
//         vector<int> vec;
//         int i = r, j = c;
//         while (i < n && j < n) {
//             vec.push_back(grid[i][j]);
//             i++, j++;
//         }
//         if (asc) {
//             sort(begin(vec), end(vec));
//         } else {
//             sort(begin(vec), end(vec), greater<int>());
//         }
//         i = r, j = c;
//         for (int& val : vec) {
//             grid[i][j] = val;
//             i++, j++;
//         }
//         return;
//     }

//     vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
//         n = grid.size();

//         for (int row = 0; row < n; row++) {
//             sortDiagonal(row, 0, grid, false);
//         }

//         for (int col = 1; col < n; col++) {
//             sortDiagonal(0, col, grid, true);
//         }

//         return grid;
//     }
// };
