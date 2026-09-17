class Solution {
    int M = 1_000_000_007;

    public int numberOfSets(int n, int K) {

        int[][] dp = new int[n + 1][n + 1];

        for (int i = 0; i <= n - 1; i++) {
            dp[0][i] = 1;
        }

        for (int k = 1; k <= K; k++) {
            int[] prevRowSum = new int[n + 1];
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k-1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--) {
                int take = prevRowSum[i + 1];

                int skip = dp[k][i + 1] % M;

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }

}
