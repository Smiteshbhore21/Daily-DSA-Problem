class Solution {
public:
    int m, n;
    int oldColor;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        m = image.size();
        n = image[0].size();
        oldColor = image[sr][sc];
        solve(image, sr, sc, color);
        return image;
    }

    bool isSafe(int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;
        return true;
    }

    void solve(vector<vector<int>>& image, int row, int col, int color) {
        if (!isSafe(row, col)) {
            return;
        }
        if (image[row][col] != oldColor || image[row][col] == color)
            return;
        image[row][col] = color;
        solve(image, row + 1, col, color);
        solve(image, row - 1, col, color);
        solve(image, row, col - 1, color);
        solve(image, row, col + 1, color);
    }
};
