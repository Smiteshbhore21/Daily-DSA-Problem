using PP = pair<int, pair<int, int>>;
class Solution {
public:
    // L R U D
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> boundaryCells;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // left most and right most col i.e. (0, n-1)
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // top most and bottom most row i.e. (0, m-1)
        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        while (!boundaryCells.empty()) {
            PP curr = boundaryCells.top();
            boundaryCells.pop();

            int height = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            // find neighbors
            for (vector<int>& dir : dirs) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                    !visited[i_][j_]) {
                    water += max(height - heightMap[i_][j_], 0);

                    boundaryCells.push(
                        {max(height, heightMap[i_][j_]), {i_, j_}});

                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};
// class Solution {
// #define pip pair<int, pair<int, int>>

//     bool isValid(int& x, int& y, int& m, int& n) {
//         return (x >= 0 and x < m and y >= 0 and y < n);
//     }

// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int m = heightMap.size();
//         int n = heightMap[0].size();
//         if (m < 3 or n < 3)
//             return 0;

//         priority_queue<pip, vector<pip>, greater<pip>> minheap;
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 or i == m - 1 or j == 0 or j == n - 1) {
//                     minheap.push(make_pair(heightMap[i][j], make_pair(i, j)));
//                     visited[i][j] = true;
//                 }
//             }
//         }

//         int level = 0;
//         int trapped_water = 0;
//         vector<int> dir = {-1, 0, 1, 0, -1};

//         while (!minheap.empty()) {
//             pip curr = minheap.top();
//             minheap.pop();

//             int heigth = curr.first;
//             int x = curr.second.first;
//             int y = curr.second.second;
//             level = max(level, heigth);

//             for (int i = 0; i < 4; i++) {
//                 int newX = x + dir[i];
//                 int newY = y + dir[i + 1];
//                 if (isValid(newX, newY, m, n) and !visited[newX][newY]) {
//                     visited[newX][newY] = true;
//                     minheap.push(make_pair(heightMap[newX][newY],
//                                            make_pair(newX, newY)));
//                     if (heightMap[newX][newY] < level)
//                         trapped_water += level - heightMap[newX][newY];
//                 }
//             }
//         }
//         return trapped_water;
//     }
// };
