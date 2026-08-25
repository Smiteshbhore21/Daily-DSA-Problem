class Solution {
    public int missingMultiple(int[] nums, int k) {
        boolean[] present = new boolean[101];

        int n = nums.length;

        for (int i = 0; i < n; i++) {
            present[nums[i]] = true;
        }

        int i = 1;
        while (true) {
            if ((i * k) >= 101 || !present[i * k])
                return i * k;
            i++;
        }
    }
}
