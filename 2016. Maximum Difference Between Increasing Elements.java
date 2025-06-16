// O(N) -->
class Solution {
    public int maximumDifference(int[] nums) {
        int n = nums.length;
        int minEle = nums[0], ans = -1;
        for (int i = 1; i < n; i++) {
            if (minEle < nums[i])
                ans = Math.max(nums[i] - minEle, ans);
            else
                minEle = Math.min(minEle, nums[i]);
        }
        return ans;
    }
}

// O(N^2) -->
// class Solution {
//     public int maximumDifference(int[] nums) {
//         int n = nums.length;
//         int ans = -1;
//         for (int i = 0; i < n; i++) {
//             for (int j = i+1; j < n; j++) {
//                 if(nums[i] < nums[j])
//                     ans = Math.max(ans, nums[j] - nums[i]);
//             }
//         }
//         return ans;
//     }
// }
