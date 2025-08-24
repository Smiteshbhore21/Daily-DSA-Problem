class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int i = 0, n = nums.size(), j = 0;
        int ans = 0;
        while (j < n) {
            if (nums[j] == 0)
                zeroCount++;
            while (zeroCount == 2) {
                if (nums[i] == 0)
                    zeroCount--;
                i++;
            }
            ans = max(ans, j - i);
            j++;
        }
        return ans;
    }
};
