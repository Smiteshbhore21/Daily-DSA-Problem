class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] diff = new int[n + 1];
        for (int[] query : queries) {
            diff[query[0]] += 1;
            diff[query[1] + 1] -= 1;
        }
        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            diff[i] = cumSum;
            if (diff[i] < nums[i])
                return false;
        }
        return true;
    }
}
