// Bottom-Up -->
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> memo(n, INT_MIN);
        memo[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target)
                    memo[i] = max(memo[i], 1 + memo[j]);
            }
        }
        return memo[0] < 0 ? -1 : memo[0];
    }
};

// Recursion -->
// class Solution {
// public:
//     int n;
//     int memo[1001];
//     int maximumJumps(vector<int>& nums, int target) {
//         n = nums.size();
//         fill(begin(memo), end(memo), INT_MIN);
//         int result = solve(0, nums, target);
//         return result < 0 ? -1 : result;
//     }
//     int solve(int i, vector<int>& nums, int& target) {
//         if (i == n - 1)
//             return 0;
//         if (memo[i] != INT_MIN)
//             return memo[i];
//         int result = INT_MIN;
//         for (int j = i + 1; j < n; j++) {
//             if (abs(nums[i] - nums[j]) <= target) {
//                 result = max(result, solve(j, nums, target) + 1);
//             }
//         }
//         return memo[i] = result;
//     }
// };
