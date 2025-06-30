class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int x : nums) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        int n = nums.length, ans = 0;
        for (int i = 0; i < n; i++) {
            if (mp.containsKey(nums[i] + 1)) {
                ans = Math.max(ans,
                        mp.get(nums[i]) + mp.get(nums[i] + 1));
            }
        }
        return ans;
    }
}
