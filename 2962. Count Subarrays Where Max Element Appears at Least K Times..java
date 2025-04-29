class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length, i = 0, j = 0;
        long ans = 0;
        int maxEle = nums[0];
        for (int l = 1; l < n; l++)
            if (maxEle < nums[l])
                maxEle = nums[l];
        int maxEleCount = 0;
        while (j < n) {
            if (nums[j] == maxEle)
                maxEleCount++;
            while (maxEleCount == k) {
                ans += (n - j);
                if (nums[i] == maxEle)
                    maxEleCount--;
                i++;
            }
            j++;
        }
        return ans;
    }
}
