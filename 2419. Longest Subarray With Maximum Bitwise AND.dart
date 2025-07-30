class Solution {
  int longestSubarray(List<int> nums) {
    int maxEle = nums[0];
        for (int x in nums) {
            if (x > maxEle)
                maxEle = x;
        }
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n;) {
            int contiCount = 0;
            while (i < n && nums[i] == maxEle) {
                contiCount++;
                i++;
            }
            if (contiCount == 0) {
                i++;
            } else {
                ans = max(contiCount, ans);
            }
        }
        return ans;
  }
}
