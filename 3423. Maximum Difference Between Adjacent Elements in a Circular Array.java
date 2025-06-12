class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int ans = Integer.MIN_VALUE, n = nums.length;
        for (int i = 0; i < n; i++)
            ans = Math.max(ans, Math.abs(nums[i] - nums[(i + 1) % n]));
        return ans;
    }
}
