int MOD = 1e9 + 7;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (auto query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            while (l <= r) {
                nums[l] = (1ll * nums[l] * v) % MOD;
                l += k;
            }
        }

        int result = 0;
        for (int& num : nums) {
            result ^= num;
        }
        return result;
    }
};
