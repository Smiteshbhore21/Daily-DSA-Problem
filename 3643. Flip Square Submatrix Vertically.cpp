class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int sR = x;
        int eR = x + k - 1;
        int sC = y;
        int eC = y + k - 1;

        for (int i = sR; i <= eR; i++) {
            for (int j = sC; j <= eC; j++) {
                swap(grid[i][j], grid[eR][j]);
            }
            eR--;
        }

        return grid;
    }
};
