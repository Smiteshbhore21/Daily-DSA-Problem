class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;

        HashMap<Integer, Integer> freq = new HashMap<>();

        int i = 0;
        int j = 0;
        int result = 0;

        while (j < n) {
            freq.put(nums[j], freq.getOrDefault(nums[j], 0) + 1);

            while (freq.get(nums[j]) > k) {
                freq.put(nums[i], freq.get(nums[i]) - 1);
                i++;
            }

            result = Math.max(result, j - i + 1);

            j++;
        }

        return result;
    }
}
