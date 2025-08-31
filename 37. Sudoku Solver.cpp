class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(d, i, j, board)) {
                            board[i][j] = d;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(char target, int r, int c, vector<vector<char>>& grid) {
        for (int i = 0; i < 9; i++) {
            if (target == grid[i][c] || target == grid[r][i])
                return false;
        }
        int i_start = r / 3 * 3;
        int j_start = c / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i_start + i][j_start + j] == target)
                    return false;
            }
        }
        return true;
    }
};
