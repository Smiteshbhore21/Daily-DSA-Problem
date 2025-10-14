class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currRun++;
            } else {
                prevRun = currRun;
                currRun = 1;
            }

            if (currRun >= 2 * k)
                return true;

            if (min(prevRun, currRun) >= k)
                return true;
        }
        return false;
    }
};

// O(n^2) -->
// class Solution {
// public:
//     bool hasIncreasingSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (k == 1 && n >= 2)
//             return true;
//         for (int start = 0; start < n; start++) {
//             if (isIncreasing(nums, start, start + k) &&
//                 isIncreasing(nums, start + k, start + (2 * k))) {
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool isIncreasing(vector<int>& nums, int start, int end) {
//         if (nums.size() < end)
//             return false;
//         for (int i = start + 1; i < end; i++) {
//             if (nums[i - 1] >= nums[i])
//                 return false;
//         }
//         return true;
//     }
// };
