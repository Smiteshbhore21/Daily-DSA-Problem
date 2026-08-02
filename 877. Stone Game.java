// class Solution {
//     public boolean stoneGame(int[] piles) {
//         return true;
//     }
// }

class Solution {

    private int[][] memo;

    public boolean stoneGame(int[] piles) {
        int n = piles.length;

        memo = new int[501][501];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        int total_score = Arrays.stream(piles).sum();

        int p1 = solve(0, n - 1, piles);

        int p2 = total_score - p1;

        return p1 > p2;
    }

    public int solve(int i, int j, int[] piles) {
        if (i > j)
            return 0;

        if (i == j)
            return piles[i];
        
        if (memo[i][j] != -1)
            return memo[i][j];

        int take_i = piles[i] + Math.min(solve(i + 2, j, piles), solve(i + 1, j - 1, piles));
        int take_j = piles[j] + Math.min(solve(i, j - 2, piles), solve(i + 1, j - 1, piles));

        memo[i][j] = Math.max(take_i, take_j);

        return memo[i][j];
    }
}
