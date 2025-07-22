class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;

        int[] cumSum = new int[n];
        cumSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            cumSum[i] = cumSum[i - 1] + nums[i];

        int[] mp = new int[10001];
        Arrays.fill(mp, -1);
        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            i = Math.max(i, mp[nums[j]] + 1);
            int jthSum = cumSum[j];
            int ithSum = i - 1 < 0 ? 0 : cumSum[i - 1];
            ans = Math.max(ans, jthSum - ithSum);
            mp[nums[j]] = j;
            j++;
        }
        return ans;
    }
}
