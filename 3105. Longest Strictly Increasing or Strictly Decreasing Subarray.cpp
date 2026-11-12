class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int increaseLen = 1;
        int decreaseLen = 1;

        int currInc = 1;
        int currDec = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                currDec++;
                if (currInc != 1) {
                    currInc = 1;
                }
                decreaseLen = max(decreaseLen, currDec);
            } else if (nums[i - 1] < nums[i]) {
                currInc++;
                if (currDec != 1) {
                    currDec = 1;
                }
                increaseLen = max(increaseLen, currInc);
            } else {
                currInc = 1;
                currDec = 1;
            }
        }

        return max(increaseLen, decreaseLen);
    }
};

// Feb 03, 2025 -->
// class Solution {
// public:
//     int longestMonotonicSubarray(vector<int>& nums) {
//         int incre = 1, decre = 1, n = nums.size(), ans = 1;
//         for (int i = 1; i < n; i++) {
//             if (nums[i - 1] > nums[i]) {
//                 decre++;
//                 incre = 1;
//             } else if (nums[i - 1] < nums[i]) {
//                 incre++;
//                 decre = 1;
//             } else {
//                 incre = 1;
//                 decre = 1;
//             }
//             ans = max(ans, incre);
//             ans = max(ans, decre);
//         }
//         return ans;
//     }
// };
