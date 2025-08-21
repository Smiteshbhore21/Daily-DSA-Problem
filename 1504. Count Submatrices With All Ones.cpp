class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int result = 0;
        int m = mat.size(), n = mat[0].size();
        for (int startRow = 0; startRow < m; startRow++) {
            vector<int> vec(n, 1);
            for (int endRow = startRow; endRow < m; endRow++) {
                for (int col = 0; col < n; col++) {
                    vec[col] = vec[col] & mat[endRow][col];
                }

                result += OneDArrayCount(vec);
            }
        }
        return result;
    }

    int OneDArrayCount(vector<int>& vec) {
        int cons = 0, subCount = 0;
        for (int& val : vec) {
            if (val == 0)
                cons = 0;
            else
                cons++;
            subCount += cons;
        }
        return subCount;
    }
};
