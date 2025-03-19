class Solution {
  int minOperations(List<int> nums) {
     int n = nums.length, ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                nums[i] = 1-nums[i];
                nums[i + 1] = 1-nums[i + 1];
                nums[i + 2] = 1-nums[i + 2];
                ans++;
            }
        }
        return (nums[n - 2]==1 && nums[n - 1]==1) ? ans : -1;
  }
}
