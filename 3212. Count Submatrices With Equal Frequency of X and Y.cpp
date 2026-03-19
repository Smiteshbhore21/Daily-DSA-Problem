using p = pair<int, int>;
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<p>> prefix(m, vector<p>(n, {0, 0}));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X')
                    prefix[i][j].first = 1;
                else if (grid[i][j] == 'Y')
                    prefix[i][j].second = 1;

                if (i - 1 >= 0) {
                    prefix[i][j].first += prefix[i - 1][j].first;

                    prefix[i][j].second += prefix[i - 1][j].second;
                }

                if (j - 1 >= 0) {
                    prefix[i][j].first += prefix[i][j - 1].first;

                    prefix[i][j].second += prefix[i][j - 1].second;
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    prefix[i][j].first -= prefix[i - 1][j - 1].first;
                    prefix[i][j].second -= prefix[i - 1][j - 1].second;
                }

                if (prefix[i][j].first >= 1 &&
                    prefix[i][j].first == prefix[i][j].second)
                    count++;
            }
        }
        return count;
    }
};
