class Solution {
public:
    long long total = 0;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = 0;
        int n = 0;
        m = grid.size();
        n = grid[0].size();
        total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        // Horizontal
        if (checkHorCut(grid))
            return true;

        reverse(grid.begin(), grid.end());

        if (checkHorCut(grid))
            return true;

        reverse(grid.begin(), grid.end());

        // Vertical
        vector<vector<int>> transpose(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transpose[j][i] = grid[i][j];
            }
        }

        if (checkHorCut(transpose))
            return true;

        reverse(transpose.begin(), transpose.end());

        if (checkHorCut(transpose))
            return true;

        return false;
    }

    bool checkHorCut(vector<vector<int>>& grid) {
        int m = 0;
        int n = 0;
        m = grid.size();
        n = grid[0].size();
        unordered_set<long long> st;
        long long top = 0;
        for (int i = 0; i <= m - 2; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }
            long long bottom = total - top;
            long long diff = top - bottom;
            if (diff == 0)
                return true;
            if (diff == grid[0][0])
                return true;
            if (diff == grid[0][n - 1])
                return true;
            if (diff == grid[i][0])
                return true;
            if (i > 0 && n > 1 && st.count(diff))
                return true;
        }
        return false;
    }
};
