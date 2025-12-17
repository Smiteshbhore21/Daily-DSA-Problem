class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        long long t[1001][501][3];
        int n = prices.size();
        for (int i = 0; i <= k; i++) {
            t[n][i][0] = 0;
            t[n][i][1] = INT_MIN;
            t[n][i][2] = INT_MIN;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int K = 0; K <= k; K++) {
                t[i][K][0] = t[i + 1][K][0];
                if (K > 0) {
                    // case 0
                    t[i][K][0] =
                        max(t[i][K][0], max(-prices[i] + t[i + 1][K][1],
                                            prices[i] + t[i + 1][K][2]));
                }
                // case 1
                t[i][K][1] = t[i + 1][K][1];
                if (K > 0)
                    t[i][K][1] =
                        max(t[i][K][1], prices[i] + t[i + 1][K - 1][0]);

                // case 2
                t[i][K][2] = t[i + 1][K][2];
                if (K > 0)
                    t[i][K][2] =
                        max(t[i][K][2], -prices[i] + t[i + 1][K - 1][0]);
            }
        }
        return t[0][k][0];
    }
};

// class Solution {
// public:
//     int n = 0;
//     long long t[1001][501][3];
//     long long maximumProfit(vector<int>& prices, int k) {
//         this->n = prices.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j <= k; j++) {
//                 for (int k = 0; k < 3; k++) {
//                     t[i][j][k] = INT_MIN;
//                 }
//             }
//         }
//         return solve(0, k, 0, prices);
//     }
//     long long solve(int i, int k, int casee, vector<int>& prices) {
//         if (k == 0)
//             return 0;
//         if (i == n) {
//             if (casee == 0)
//                 return 0;
//             return INT_MIN; // unfinished transactions
//         }
//         if (t[i][k][casee] != INT_MIN) {
//             return t[i][k][casee];
//         }
//         long long dontTake = solve(i + 1, k, casee, prices);
//         long long take = INT_MIN;
//         if (casee == 0) { // fresh buy or shortsell
//             take = max((-prices[i]) + solve(i + 1, k, 1, prices),
//                        prices[i] + solve(i + 1, k, 2, prices));
//         } else if (casee == 1) { // sell
//             take = prices[i] + solve(i + 1, k - 1, 0, prices);
//         } else { // short buy
//             take = (-prices[i]) + solve(i + 1, k - 1, 0, prices);
//         }
//         return t[i][k][casee] = max(take, dontTake);
//     }
// };
