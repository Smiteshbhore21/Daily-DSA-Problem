class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] minEle = new int[n];
        minEle[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minEle[i] = Math.min(nums[i], minEle[i + 1]);
        }

        int maxEle = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            maxEle = Math.max(maxEle, nums[i]);

            int instability = maxEle - minEle[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
}
