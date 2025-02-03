class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incre = 1, decre = 1, n = nums.size(), ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                decre++;
                incre = 1;
            } else if (nums[i - 1] < nums[i]) {
                incre++;
                decre = 1;
            } else {
                incre = 1;
                decre = 1;
            }
            ans = max(ans, incre);
            ans = max(ans, decre);
        }
        return ans;
    }
};
