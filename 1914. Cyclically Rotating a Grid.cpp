class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;
        for (int layer = 0; layer < layers; layer++) {
            vector<int> nums;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // Top
            for (int j = left; j <= right; j++) {
                nums.push_back(grid[top][j]);
            }

            // Right
            for (int i = top + 1; i <= bottom - 1; i++) {
                nums.push_back(grid[i][right]);
            }

            // Bottom
            for (int j = right; j >= left; j--) {
                nums.push_back(grid[bottom][j]);
            }

            // Left
            for (int i = bottom - 1; i >= top + 1; i--) {
                nums.push_back(grid[i][left]);
            }

            int len = nums.size();

            int norm_k = k % len;

            rotate(begin(nums), begin(nums) + norm_k, end(nums));

            int idx = 0;

            // Top
            for (int j = left; j <= right; j++) {
                grid[top][j] = nums[idx++];
            }

            // Right
            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = nums[idx++];
            }

            // Bottom
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = nums[idx++];
            }

            // Left
            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = nums[idx++];
            }
        }
        return grid;
    }
};
