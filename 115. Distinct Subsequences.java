class Solution {
    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();

        int[][] dp = new int[s.length() + 1][t.length() + 1];

        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        for (int j = 0; j < m; j++) {
            dp[n][j] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s.charAt(i) == t.charAt(j)) {
                    dp[i][j] = dp[i + 1][j + 1]
                            + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][0];
    }
}

// Recursion + Memo -->
// class Solution {
//     int n;
//     String target;
//     HashMap<Integer, HashMap<Integer, Integer>> memo = new HashMap<>();
//     public int numDistinct(String s, String t) {
//         target = t;
//         n = s.length();
//         return solve(s, 0, 0);
//     }
//     public int solve(String s, int i, int j) {
//         if (j == target.length()) {
//             return 1;
//         }
//         if (i == s.length()) {
//             return 0;
//         }
//         if (memo.containsKey(i) && memo.get(i).containsKey(j)) {
//             return memo.get(i).get(j);
//         }
//         int ans;
//         if (s.charAt(i) == target.charAt(j)) {
//             ans = solve(s, i + 1, j + 1)
//                     + solve(s, i + 1, j);
//         } else {
//             ans = solve(s, i + 1, j);
//         }
//         memo.putIfAbsent(i, new HashMap<>());
//         memo.get(i).put(j, ans);
//         return ans;
//     }
// }
