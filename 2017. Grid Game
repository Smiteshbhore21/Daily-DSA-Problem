class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long downSum = 0;
        long long upSum = 0;
        long long ans = LONG_MAX;
        for (int i = 0; i < n; i++)
            upSum += grid[0][i];

        for (int i = 0; i < n; i++) {
            upSum -= grid[0][i];

            ans = min(ans, max(upSum, downSum));

            downSum += grid[1][i];
        }

        return ans;
    }
};
