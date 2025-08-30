class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<int> col;
            unordered_set<int> row;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (col.find(board[i][j]) != col.end())
                        return false;
                    col.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (row.find(board[j][i]) != row.end())
                        return false;
                    row.insert(board[j][i]);
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!boxCheck(i, j, board))
                    return false;
            }
        }

        return true;
    }
    bool boxCheck(int iR, int jC, vector<vector<char>>& board) {
        int m = iR + 3;
        int n = jC + 3;
        unordered_set<int> box;
        for (int i = iR; i < m; i++) {
            for (int j = jC; j < n; j++) {
                if (board[i][j] != '.') {
                    if (box.find(board[i][j]) != box.end())
                        return false;
                    box.insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
