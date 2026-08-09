class Solution {
    int n;
    int[][][] t;

    public int stoneGameII(int[] piles) {
        n = piles.length;

        t = new int[2][101][101];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 101; j++) {
                Arrays.fill(t[i][j], -1);
            }
        }

        int aliceStone = solve(1, 0, 1, piles);

        return aliceStone;
    }

    public int solve(int person, int i, int M, int[] piles) {
        if (i >= n)
            return 0;

        if (t[person][i][M] != -1)
            return t[person][i][M];

        int maxStone = person == 1 ? -1 : Integer.MAX_VALUE;
        int stones = 0;

        for (int x = 1; x <= Math.min(n - i, 2 * M); x++) {
            stones += piles[i + x - 1];

            if (person == 1) { //Alice
                maxStone = Math.max(maxStone, stones + solve(0, i + x, Math.max(M, x), piles));
            } else { //Bob
                maxStone = Math.min(maxStone, solve(1, i + x, Math.max(M, x), piles));
            }
        }

        t[person][i][M] = maxStone;

        return maxStone;
    }
}
