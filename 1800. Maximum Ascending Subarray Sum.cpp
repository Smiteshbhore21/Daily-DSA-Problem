class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), maxi = nums[0], ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i])
                maxi += nums[i];
            else {
                ans = max(ans, maxi);
                maxi = nums[i];
            }
        }
        ans = max(ans, maxi);
        return ans;
    }
};
