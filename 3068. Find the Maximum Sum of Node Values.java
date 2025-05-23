class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long n = nums.length, sum = 0, minLoss = Integer.MAX_VALUE, count = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] ^ k) > nums[i]) {
                sum += (nums[i] ^ k);
                count++;
            } else {
                sum += nums[i];
            }
            minLoss = Math.min(minLoss, Math.abs(nums[i] - (nums[i] ^ k)));
        }
        if (count % 2 == 1)
            return sum - minLoss;
        return sum;
    }
}
