class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid[0].length, m = grid.length;
        int[] ans = { 0, 0 }, countVec = new int[n * m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                countVec[grid[i][j] - 1]++;
            }
        }
        for (int j = 0; j < n * m; j++) {
            if (countVec[j] == 2)
                ans[0] = j + 1;
            if (countVec[j] == 0)
                ans[1] = j + 1;
        }
        return ans;
    }
}
