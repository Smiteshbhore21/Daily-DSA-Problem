class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> st;

        vector<vector<int>> d1(m, vector<int>(n, 0));
        vector<vector<int>> d2(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                d1[r][c] = grid[r][c];
                if (r - 1 >= 0 && c - 1 >= 0)
                    d1[r][c] += d1[r - 1][c - 1];
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                d2[r][c] = grid[r][c];
                if (r - 1 >= 0 && c + 1 < n)
                    d2[r][c] += d2[r - 1][c + 1];
            }
        }

        auto addSet = [&](int sum) {
            st.insert(sum);

            if (st.size() > 3) {
                st.erase(st.begin());
            }
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                addSet(grid[r][c]);

                for (int side = 1; r - side >= 0 && r + side < m &&
                                   c - side >= 0 && c + side < n;
                     side++) {

                    int sum = 0;
                    int top_r = r - side, top_c = c;
                    int right_r = r, right_c = c + side;
                    int bottom_r = r + side, bottom_c = c;
                    int left_r = r, left_c = c - side;

                    // top to right corner
                    sum += d1[right_r][right_c];
                    if (top_r - 1 >= 0 && top_c - 1 >= 0)
                        sum -= d1[top_r - 1][top_c - 1];

                    // right to bottom corner
                    sum += d2[bottom_r][bottom_c];
                    if (right_r - 1 >= 0 && right_c + 1 < n)
                        sum -= d2[right_r - 1][right_c + 1];

                    // bottom to left corner
                    sum += d1[bottom_r][bottom_c];
                    if (left_r - 1 >= 0 && left_c - 1 >= 0)
                        sum -= d1[left_r - 1][left_c - 1];

                    // left to top corner
                    sum += d2[left_r][left_c];
                    if (top_r - 1 >= 0 && top_c + 1 < n)
                        sum -= d2[top_r - 1][top_c + 1];

                    // remove corners counted twice
                    sum -= grid[top_r][top_c];
                    sum -= grid[right_r][right_c];
                    sum -= grid[bottom_r][bottom_c];
                    sum -= grid[left_r][left_c];

                    addSet(sum);
                }
            }
        }
        return vector<int>(rbegin(st), rend(st));
    }
};
