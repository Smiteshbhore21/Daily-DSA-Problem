class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        vector<int> factories;
        for (auto& f : factory) {
            while (f[1]--) {
                factories.push_back(f[0]);
            }
        }
        int n = robot.size();
        int m = factories.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e12));

        for (int j = 0; j <= m; j++) {
            dp[n][j] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                long long take =
                    abs((long long)robot[i] - factories[j]) + dp[i + 1][j + 1];

                long long skip = dp[i][j + 1];

                dp[i][j] = min(take, skip);
            }
        }
        return dp[0][0];
    }
};

// Memo + Recursion
// class Solution {
// public:
//     vector<int> robot, factory;
//     long long memo[101][10001] = {{-1}};
//     long long minimumTotalDistance(vector<int>& robot,
//                                    vector<vector<int>>& factory) {
//         memset(memo, -1, sizeof(memo));
//         sort(begin(robot), end(robot));
//         sort(begin(factory), end(factory));
//         this->robot = robot;
//         for (auto& f : factory) {
//             while (f[1]--) {
//                 this->factory.push_back(f[0]);
//             }
//         }
//         return solve(0, 0);
//     }
//     long long solve(int i, int j) {
//         if (i >= robot.size())
//             return 0;
//         if (j >= factory.size())
//             return 1e16;
//         if (memo[i][j] != (long long)-1)
//             return memo[i][j];
//         long long take = abs((long long)robot[i] - factory[j]) + solve(i + 1,
//         j + 1); long long skip = solve(i, j + 1); return memo[i][j] =
//         min(take, skip);
//     }
// };
