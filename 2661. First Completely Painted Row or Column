class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), x = arr.size();
        vector<pair<int, int>> mp(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j] - 1] = make_pair(i, j);
            }
        }

        vector<int> row(m), col(n);
        for (int i = 0; i < x; i++) {
            row[mp[arr[i] - 1].first]++;
            col[mp[arr[i] - 1].second]++;
            if (row[mp[arr[i] - 1].first] == n ||
                col[mp[arr[i] - 1].second] == m)
                return i;
        }
        return arr.size();
    }
};
