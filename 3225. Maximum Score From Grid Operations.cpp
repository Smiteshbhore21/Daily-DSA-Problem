typedef long long ll;
class Solution {
public:
    int n;
    vector<vector<ll>> colPrefSum;
    ll memo[2][101][101];

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        memset(memo, -1, sizeof(memo));

        colPrefSum.resize(n + 1, vector<ll>(n + 1, 0));
        for (int col = 1; col <= n; col++) {
            for (int row = 1; row <= n; row++) {
                colPrefSum[row][col] =
                    colPrefSum[row - 1][col] + grid[row - 1][col - 1];
            }
        }

        return solve(false, 0, 0, grid);
    }

    ll solve(bool prevTaken, int prevHeight, int col,
             vector<vector<int>>& grid) {
        if (col == n)
            return 0;

        ll result = 0;

        if (memo[prevTaken][prevHeight][col] != -1)
            return memo[prevTaken][prevHeight][col];

        for (int height = 0; height <= n; height++) {
            ll prevColScore = 0;
            ll currColScore = 0;

            if (!prevTaken && col - 1 >= 0 && height > prevHeight) {
                prevColScore +=
                    colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if (height < prevHeight) {
                currColScore += colPrefSum[prevHeight][col + 1] -
                                colPrefSum[height][col + 1];
            }

            ll currColScoreTaken = currColScore + prevColScore +
                                   solve(true, height, col + 1, grid);

            ll currColScoreNotTaken =
                prevColScore + solve(false, height, col + 1, grid);

            result = max({currColScoreTaken, currColScoreNotTaken, result});
        }
        return memo[prevTaken][prevHeight][col] = result;
    }
};
