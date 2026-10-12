class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitsCnt(32, 0);

        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit))
                    bitsCnt[bit]++;
            }
        }

        long long result = 0;
        while (k--) {
            long long curr = 0;
            for (int bit = 0; bit < 32; bit++) {
                if (bitsCnt[bit] > 0) {
                    bitsCnt[bit]--;
                    curr = (curr | (1 << bit));
                }
            }
            result = (result + (curr * curr)) % MOD;
        }

        return result;
    }
};
