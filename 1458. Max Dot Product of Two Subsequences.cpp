class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, -1e9));
        long long result = -1e9;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                long long val = nums1[i] * nums2[j];
                long long take_i_j = val + dp[i + 1][j + 1];
                long long take_i = dp[i][j + 1];
                long long take_j = dp[i + 1][j];
                dp[i][j] = max({val, take_i_j, take_i, take_j});
                result = max(dp[i][j], result);
            }
        }
        return (int)result;
    }
};

// class Solution {
// public:
//     int m, n;
//     vector<vector<int>> dp;
//     int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//         m = nums1.size();
//         n = nums2.size();
//         dp.resize(m + 1, vector<int>(n + 1, -1e9));
//         return solve(nums1, nums2, 0, 0);
//     }
//     int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
//         if (i == m || j == n)
//             return -1e9;
//         if (dp[i][j] != -1e9)
//             return dp[i][j];
//         int val = nums1[i] * nums2[j];
//         int take_i_j = val + solve(nums1, nums2, i + 1, j + 1);
//         int take_i = solve(nums1, nums2, i, j + 1);
//         int take_j = solve(nums1, nums2, i + 1, j);
//         return dp[i][j] = max({val, take_i_j, take_i, take_j});
//     }
// };
