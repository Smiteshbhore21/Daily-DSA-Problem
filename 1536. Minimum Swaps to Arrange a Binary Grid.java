class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] zeroCntRow = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1)
                    break;
                zeroCntRow[i]++;
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            int reqZeros = n - i - 1;
            int j = i;
            while (j < n && zeroCntRow[j] < reqZeros)
                j++;
            if (j == n)
                return -1;
            result += (j - i);
            while (j > i) {
                int temp = zeroCntRow[j];
                zeroCntRow[j] = zeroCntRow[j - 1];
                zeroCntRow[j - 1] = temp;
                j--;
            }
        }
        return result;
    }
}
