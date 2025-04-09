class Solution {
    public int minOperations(int[] nums, int k) {
        HashSet<Integer> set = new HashSet<Integer>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] > k)
                set.add(nums[i]);
            else if (nums[i] < k)
                return -1;
        }
        return set.size();
    }
}
