class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0),
            target = totalSum / 2;
        if (totalSum % 2 != 0)
            return 0;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int& x : nums) {
            for (int i = target; i >= x; i--) {
                dp[i] = dp[i] || dp[i - x];
            }
        }
        return dp[target];
    }
};
