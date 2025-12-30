class Solution {
public:
    int m;
    int n;
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (m < 3 || n < 3)
            return 0;

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result += solve(i, j, grid);
            }
        }

        return result;
    }

    int solve(int row, int col, vector<vector<int>>& grid) {
        unordered_set<int> st;
        int prevRow = 0;
        for (int j = col; j < col + 3; j++) {
            if (j >= n || grid[row][j] > 9)
                return 0;
            prevRow += grid[row][j];
        }

        int dia1 = 0;
        int dia2 = 0;

        int col1 = 0;
        int col2 = 0;
        int col3 = 0;

        for (int i = row; i < row + 3; i++) {
            int currRow = 0;
            for (int j = col; j < col + 3; j++) {
                if (i >= m || j >= n || grid[i][j] > 9 || grid[i][j] == 0)
                    return 0;

                if (j % 3 == 0)
                    col1 += grid[i][j];
                else if (j % 3 == 1)
                    col2 += grid[i][j];
                else
                    col3 += grid[i][j];

                if (i - j == row - col)
                    dia1 += grid[i][j];

                if (i + j == (row) + (col + 2))
                    dia2 += grid[i][j];

                currRow += grid[i][j];
                st.insert(grid[i][j]);
            }
            if (prevRow != currRow)
                return 0;
            prevRow = currRow;
        }

        if (col1 == col2 && col2 == col3 && col3 == dia1 && dia1 == dia2 &&
            st.size() == 9)
            return 1;
        return 0;
    }
};
