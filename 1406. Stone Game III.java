// Bottom-Up -->
class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;

        int[] dp = new int[n + 1];

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = stoneValue[i] - dp[i + 1];

            if (i + 1 < n)
                dp[i] = Math.max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);

            if (i + 2 < n)
                dp[i] = Math.max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
        }

        int diff = dp[0];

        if (diff < 0) {
            return "Bob";
        } else if (diff > 0) {
            return "Alice";
        }
        return "Tie";
    }
}

// Recursion + Memo -> 
// class Solution {
//     private int n;
//     private int[] memo;
//     public String stoneGameIII(int[] stoneValue) {
//         n = stoneValue.length;
//         memo = new int[n + 1];
//         Arrays.fill(memo, -1);
//         int diff = solve(0, stoneValue);
//         if (diff < 0) {
//             return "Bob";
//         } else if (diff > 0) {
//             return "Alice";
//         }
//         return "Tie";
//     }
//     public int solve(int i, int[] stoneValue) {
//         if (i >= n)
//             return 0;
//         if (memo[i] != -1)
//             return memo[i];
//         int result = stoneValue[i] - solve(i + 1, stoneValue);
//         if (i + 1 < n)
//             result = Math.max(result, stoneValue[i] + stoneValue[i + 1] - solve(i + 2, stoneValue));
//         if (i + 2 < n)
//             result = Math.max(result, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(i + 3, stoneValue));
//         memo[i] = result;
//         return result;
//     }
// }
