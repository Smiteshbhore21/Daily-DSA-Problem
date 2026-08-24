class Solution {
    int n;

    public int stoneGameVIII(int[] stones) {
        n = stones.length;

        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        dp[n - 1] = stones[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int take = stones[i] - dp[i + 1];
            int skip = dp[i + 1];

            dp[i] = Math.max(take, skip);
        }

        return dp[1];
    }
}
