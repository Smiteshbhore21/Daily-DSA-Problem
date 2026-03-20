class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                set<int> val;
                for (int l = i; l <= i + k - 1; l++) {
                    for (int o = j; o <= j + k - 1; o++) {
                        val.insert(grid[l][o]);
                    }
                }

                int minAbsDiff = INT_MAX;
                auto prev = val.begin();
                auto curr = next(val.begin());

                while (curr != val.end()) {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev++;
                    curr++;
                }

                if (minAbsDiff == INT_MAX)
                    minAbsDiff = 0;

                result[i][j] = minAbsDiff;
            }
        }
        return result;
    }
};
