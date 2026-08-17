// Bottom-up --> O(n^3) -->
class Solution {
    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;

        int[] prefSum = new int[n];
        prefSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + stoneValue[i];
        }

        int[][] dp = new int[501][501];

        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {
                for (int mid = l; mid < r; mid++) {
                    int leftSum = prefSum[mid] - (l - 1 >= 0 ? prefSum[l - 1] : 0);
                    int rightSum = prefSum[r] - prefSum[mid];
                    if (leftSum < rightSum) {
                        dp[l][r] = Math.max(dp[l][r], leftSum + dp[l][mid]);
                    } else if (leftSum > rightSum) {
                        dp[l][r] = Math.max(dp[l][r], rightSum + dp[mid + 1][r]);
                    } else {
                        dp[l][r] = Math.max(dp[l][r], leftSum + dp[l][mid]);
                        dp[l][r] = Math.max(dp[l][r], rightSum + dp[mid + 1][r]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
}

// Recursion + Memo -> O(n^3) -->
// class Solution {
//     int[] prefSum;
//     int[][] memo;
//     public int stoneGameV(int[] stoneValue) {
//         int n = stoneValue.length;
//         memo = new int[501][501];
//         for (int i = 0; i < 501; i++) {
//             Arrays.fill(memo[i], -1);
//         }
//         prefSum = new int[n];
//         prefSum[0] = stoneValue[0];
//         for (int i = 1; i < n; i++) {
//             prefSum[i] = prefSum[i - 1] + stoneValue[i];
//         }
//         return solve(0, n - 1);
//     }
//     public int solve(int l, int r) {
//         if (l >= r)
//             return 0;
//         if (memo[l][r] != -1)
//             return memo[l][r];
//         int score = 0;
//         for (int mid = l; mid < r; mid++) {
//             int leftSum = prefSum[mid] - (l - 1 >= 0 ? prefSum[l - 1] : 0);
//             int rightSum = prefSum[r] - prefSum[mid];
//             if (leftSum < rightSum) {
//                 score = Math.max(score, leftSum + solve(l, mid));
//             } else if (leftSum > rightSum) {
//                 score = Math.max(score, rightSum + solve(mid + 1, r));
//             } else {
//                 score = Math.max(score, leftSum + solve(l, mid));
//                 score = Math.max(score, rightSum + solve(mid + 1, r));
//             }
//         }
//         memo[l][r] = score;
//         return score;
//     }
// }
