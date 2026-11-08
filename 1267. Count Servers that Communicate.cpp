// Nov 2026 -->
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows(m, 0), cols(n, 0);

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1))
                    result++;
            }
        }

        return result;
    }
};

// Jan 2025 -->
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        //1st Approuch
        // int m = grid.size(), n = grid[0].size(), ans = 0;
        // queue<pair<int, int>> ones;
        // for (int i = 0; i < m; i++)
        //     for (int j = 0; j < n; j++)
        //         if (grid[i][j] == 1)
        //             ones.push(make_pair(i, j));

        // while (!ones.empty()) {
        //     int r = ones.front().first, c = ones.front().second, oneCount =
        //     0;

        //     for (int i = 0; i < m; i++)
        //         if (grid[i][c] == 1)
        //             oneCount++;

        //     for (int i = 0; i < n; i++)
        //         if (c != i && grid[r][i] == 1)
        //             oneCount++;

        //     if (oneCount > 1)
        //         ans++;
        //     ones.pop();
        // }

        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> rowCount(m);
        vector<int> colCount(n);
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    count++;
                    rowCount[i]++;
                    colCount[j]++;
                }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    if (rowCount[i] == 1 && colCount[j] == 1)
                        count--;
                }

        return count;
    }
};
