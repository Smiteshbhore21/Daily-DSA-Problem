class Solution {
    public int maximumLength(int[] nums) {
        int n = nums.length;
        int ans = 0, countEven = 0, countOdd = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                countEven++;
            else
                countOdd++;
        }
        int parity = nums[0] % 2;
        int alternating = 1;
        for (int i = 0; i < n; i++) {
            int currParity = nums[i] % 2;
            if (currParity != parity) {
                alternating++;
                parity = currParity;
            }
        }

        return Math.max(alternating, Math.max(countOdd, countEven));
    }
}

// class Solution {
//     public int maximumLength(int[] nums) {
//         int n = nums.length;
//         int ans = 0;
//         //Even
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % 2 == 0) {
//                 ans++;
//             }
//         }
//         //Odd
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % 2 == 1) {
//                 count++;
//             }
//         }
//         ans = Math.max(ans, count);
//         count = 0;
//         //Odd + Even
//         int parity = 1;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % 2 == parity) {
//                 parity = parity == 1 ? 0 : 1;
//                 count++;
//             }
//         }
//         ans = Math.max(ans, count);
//         count = 0;
//         //Even + Odd
//         parity = 0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % 2 == parity) {
//                 parity = parity == 1 ? 0 : 1;
//                 count++;
//             }
//         }
//         ans = Math.max(ans, count);
//         return ans;
//     }
// }
