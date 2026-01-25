class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),
             [&](const int& a, const int& b) { return a > b; });
        int result = nums[0];
        int n = nums.size();
        for (int i = 0; i <= n - k; i++) {
            result = min(result, nums[i] - nums[i + k - 1]);
        }
        return result;
    }
};
