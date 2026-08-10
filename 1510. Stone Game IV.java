class Solution {
    public boolean winnerSquareGame(int n) {
        int[] dp = new int[n + 1];

        // 1 = winning
        // 2 = losing

        dp[0] = 2;

        for (int i = 1; i <= n; i++) {

            for (int k = 1; k * k <= i; k++) {

                if (dp[i - (k * k)] == 2) {
                    dp[i] = 1;
                    break;
                }
            }

            // No square move leads to a losing state
            if (dp[i] == 0) {
                dp[i] = 2;
            }
        }

        return dp[n] == 1;
    }
}

// class Solution {
//     int[] memo;
//     public boolean winnerSquareGame(int n) {
//         memo = new int[n + 1];
//         return solve(n);
//     }
//     public boolean solve(int n) {
//         if (n == 0)
//             return false;
//         if (memo[n] != 0) {
//             if (memo[n] == 1) {
//                 return true;
//             } else {
//                 return false;
//             }
//         }
//         for (int i = 1; i * i <= n; i++) {
//             if (solve(n - (i * i)) == false) {
//                 memo[n] = 1;
//                 return true;
//             }
//         }
//         memo[n] = 2;
//         return false;
//     }
// }
