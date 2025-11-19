class Solution {
    public int findFinalValue(int[] nums, int original) {
        boolean[] present = new boolean[1001];
        for (int num : nums) {
            present[num] = true;
        }
        while (original < 1001 && present[original]) {
            original *= 2;
        }
        return original;
    }
}
