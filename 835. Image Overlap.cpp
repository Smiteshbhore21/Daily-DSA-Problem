class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int result = 0;
        for (int row_offset = (-n + 1); row_offset < n; row_offset++) {
            for (int col_offset = (-n + 1); col_offset < n; col_offset++) {
                result = max(result,
                             countOverlaps(img1, img2, row_offset, col_offset));
            }
        }

        return result;
    }

    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B,
                      int rowOffset, int colOffset) {
        int n = A.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + rowOffset >= 0 && i + rowOffset < n &&
                    j + colOffset >= 0 && j + colOffset < n) {
                    if (A[i][j] == 1 && B[i + rowOffset][j + colOffset] == 1)
                        count++;
                }
            }
        }

        return count;
    }
};
