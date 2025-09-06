class Solution {
    public long minOperations(int[][] queries) {
        long  result = 0;

        for (int[] query : queries) {
            int l = query[0];
            int r = query[1];

            long  steps = solve(l, r);
            result += (steps + 1) / 2;
        }

        return result;
    }

    public long solve(int l, int r) {
        long  L = 1, S = 1, steps = 0;

        while (L <= r) {
            long  R = 4 * L - 1;

            long  start = Math.max(L, (long)l);
            long  end = Math.min(R, (long)r);

            if (start <= end) {
                steps += (end - start + 1) * S;
            }

            S += 1;
            L = L * 4;
        }
        return steps;
    }
}
