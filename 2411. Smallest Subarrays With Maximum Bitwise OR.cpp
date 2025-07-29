class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> setBits(32, -1), ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int endIdx = i;
            for (int j = 0; j < 32; j++) {
                if ((nums[i] & (1 << j)) == 0) {
                    if (setBits[j] != -1) {
                        endIdx = max(endIdx, setBits[j]);
                    }
                } else {
                    setBits[j] = i;
                }
            }
            ans[i] = endIdx - i + 1;
        }
        return ans;
    }
};
