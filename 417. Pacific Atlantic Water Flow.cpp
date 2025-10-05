class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>>& heights, int type) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if (type == 0) {
            for (int i = 0; i < m; i++) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            for (int i = 0; i < n; i++) {
                q.push({0, i});
                vis[0][i] = 1;
            }
        } else {
            for (int i = 0; i < m; i++) {
                q.push({i, n - 1});
                vis[i][n - 1] = 1;
            }
            for (int i = 0; i < n; i++) {
                q.push({m - 1, i});
                vis[m - 1][i] = 1;
            }
        }
        int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dirs[i][0];
                int ncol = col + dirs[i][1];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                    !vis[nrow][ncol] &&
                    heights[nrow][ncol] >= heights[row][col]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return vis;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> vis1 = solve(heights, 0);
        vector<vector<int>> vis2 = solve(heights, 1);
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis1[i][j] == 1 && vis2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
