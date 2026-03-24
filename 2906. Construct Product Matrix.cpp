const int MOD = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n * m;

        vector<int> flatten(size, 0);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flatten[idx++] = grid[i][j] % MOD;
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);
        for (int i = 1, j = size - 2; i < size; i++, j--) {
            prefix[i] = (1ll * prefix[i - 1] * flatten[i - 1]) % MOD;
            suffix[j] = (1ll * suffix[j + 1] * flatten[j + 1]) % MOD;
        }

        vector<vector<int>> result(n, vector<int>(m, 0));
        idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = (1ll * prefix[idx] * suffix[idx]) % MOD;
                idx++;
            }
        }
        return result;
    }
};
