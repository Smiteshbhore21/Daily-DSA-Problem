class Solution {

    private int[][] memo;

    public boolean predictTheWinner(int[] nums) {
        int total_score = Arrays.stream(nums).sum();

        memo = new int[23][23];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        int p1 = solve(0, nums.length - 1, nums);
        int p2 = total_score - p1;

        return p1 >= p2;
    }

    public int solve(int i, int j, int[] nums) {
        if (i > j)
            return 0;

        if (i == j)
            return nums[i];

        if (memo[i][j] != -1)
            return memo[i][j];

        int take1 = nums[i] + Math.min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));
        int take2 = nums[j] + Math.min(solve(i, j - 2, nums), solve(i + 1, j - 1, nums));

        memo[i][j] = Math.max(take1, take2);

        return memo[i][j];
    }
}
