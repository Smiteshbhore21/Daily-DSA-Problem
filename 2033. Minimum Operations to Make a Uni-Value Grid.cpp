class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size(), rem = grid[0][0] % x;
        vector<int> flatten;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != rem)
                    return -1;

                flatten.push_back(grid[i][j]);
            }
        }
        sort(flatten.begin(), flatten.end());
        int mid = flatten[(m * n) / 2], ans = 0;

        for (int i = 0; i < m * n; i++) {
            ans += abs(flatten[i] - mid) / x;
        }
        return ans;
    }
};
