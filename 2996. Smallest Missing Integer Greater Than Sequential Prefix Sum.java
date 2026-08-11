class Solution {
    public int missingInteger(int[] nums) {
        int n = nums.length;

        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        int pref = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                pref += nums[i];
            } else {
                break;
            }
        }

        while (freq.containsKey(pref)) {
            pref++;
        }

        return pref;
    }
}
