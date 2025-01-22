class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> water;
        vector<vector<bool>> marked(m, vector<bool>(n, false));
        // up, right,down, left
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (isWater[r][c] == 1) {
                    isWater[r][c] = 0;
                    water.push(make_pair(r, c));
                    marked[r][c] = true;
                } else
                    isWater[r][c] = -1;
            }
        }

        while (!water.empty()) {
            int r = water.front().first;
            int c = water.front().second;
            int h = isWater[r][c];
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    marked[nr][nc] != true) {
                    isWater[nr][nc] = h + 1;
                    water.push(make_pair(nr, nc));
                    marked[nr][nc] = true;
                }
            }
            water.pop();
        }
        return isWater;
    }
};
