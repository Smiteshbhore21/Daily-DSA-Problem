class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long maxi = 0, res = 0, maxDiff = 0;
        for (int k = 0; k < n; k++) {
            res = Math.max(res, maxDiff * nums[k]);
            maxDiff = Math.max(maxDiff, maxi - nums[k]);
            maxi = Math.max(maxi, nums[k]);
        }
        return res;
    }
}
