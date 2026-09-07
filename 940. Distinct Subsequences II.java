class Solution {
    int M = 1_000_000_007;

    int[] dp;
    int[] prev;
    int[] lastSeen;

    public int distinctSubseqII(String s) {
        int n = s.length();

        dp = new int[2001];
        Arrays.fill(dp, -1);
        prev = new int[n + 1];
        lastSeen = new int[26];

        for (int i = 1; i <= n; i++) {
            int idx = s.charAt(i - 1) - 'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + M) % M;
    }

    public int solve(int n) {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int total = (2 * solve(n - 1)) % M;

        int duplicates = 0;

        if (prev[n] != 0) {
            duplicates = solve(prev[n] - 1);
            total = (total - duplicates + M) % M;
        }

        dp[n] = total;

        return total;
    }
}

// TLE() -->
// class Solution {
//     int n;
//     int mod = 1000000000 + 7;
//     HashSet<String> distinct;
//     public int distinctSubseqII(String s) {
//         distinct = new HashSet<>();
//         n = s.length();
//         solve(s, "", 0);
//         return distinct.size() % mod;
//     }
//     public void solve(String s, String curr, int i) {
//         if (i >= n) {
//             if (curr.length() != 0 && !distinct.contains(curr)) {
//                 distinct.add(curr);
//                 return;
//             }
//             return;
//         }
//         solve(s, curr + s.charAt(i), i + 1);
//         solve(s, curr, i + 1);
//     }
// }
