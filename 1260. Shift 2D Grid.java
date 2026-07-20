import java.util.ArrayList;
import java.util.List;

class Solution {

    @FunctionalInterface
    interface IntPairConsumer {
        void accept(int i, int j);
    }

    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int row = grid.length;
        int col = grid[0].length;
        int n = row * col;

        k = k % n;

        IntPairConsumer reverse = (i, j) -> {
            while (i < j) {
                int r1 = i / col, c1 = i % col;
                int r2 = j / col, c2 = j % col;

                int temp = grid[r1][c1];
                grid[r1][c1] = grid[r2][c2];
                grid[r2][c2] = temp;

                i++;
                j--;
            }
        };

        if (k > 0) {
            reverse.accept(0, n - 1);
            reverse.accept(0, k - 1);
            reverse.accept(k, n - 1);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int[] r : grid) {
            List<Integer> listRow = new ArrayList<>();
            for (int val : r) {
                listRow.add(val);
            }
            result.add(listRow);
        }

        return result;
    }
}
