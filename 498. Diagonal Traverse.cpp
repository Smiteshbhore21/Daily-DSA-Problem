class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m = mat.size(), n = mat[0].size();
        solve(0, 0, true, m, n, mat, res);
        return res;
    }

    void solve(int i, int j, bool up, int& m, int& n, vector<vector<int>>& mat,
               vector<int>& res) {
        res.push_back(mat[i][j]);
        if (up) {
            if (isValid(i - 1, j + 1, m, n)) {
                solve(i - 1, j + 1, up, m, n, mat, res);
            } else if (isValid(i, j + 1, m, n)) {
                solve(i, j + 1, !up, m, n, mat, res);
            } else if (isValid(i + 1, j, m, n)) {
                solve(i + 1, j, !up, m, n, mat, res);
            }
        } else {
            if (isValid(i + 1, j - 1, m, n)) {
                solve(i + 1, j - 1, up, m, n, mat, res);
            } else if (isValid(i + 1, j, m, n)) {
                solve(i + 1, j, !up, m, n, mat, res);
            } else if (isValid(i, j + 1, m, n)) {
                solve(i, j + 1, !up, m, n, mat, res);
            }
        }
    }

    bool isValid(int i, int j, int& m, int& n) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
};
