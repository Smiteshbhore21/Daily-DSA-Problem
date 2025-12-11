class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> min_x(n + 1, n + 1), max_x(n + 1, 0), min_y(n + 1, n + 1),
            max_y(n + 1, 0);
        for (const vector<int>& building : buildings) {
            int x = building[0];
            int y = building[1];

            min_x[y] = min(min_x[y], x);
            max_x[y] = max(max_x[y], x);

            min_y[x] = min(min_y[x], y);
            max_y[x] = max(max_y[x], y);
        }
        int result = 0;
        for (const vector<int>& building : buildings) {
            int x = building[0];
            int y = building[1];
            if (x > min_x[y] && x < max_x[y] && y > min_y[x] && y < max_y[x]) {
                result++;
            }
        }
        return result;
    }
};
