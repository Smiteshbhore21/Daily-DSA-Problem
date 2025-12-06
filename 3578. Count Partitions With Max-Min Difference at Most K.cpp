int MOD = 1e9 + 7;
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0), prefix(n + 1, 0);

        dp[0] = 1, prefix[0] = 1;

        multiset<int> s;

        int i = 0;

        for (int j = 0; j < n; j++) {
            s.insert(nums[j]);

            while (i <= j && (*s.rbegin() - *s.begin()) > k) {
                s.erase(s.find(nums[i]));
                i++;
            }
            if (i > 0) {
                dp[j + 1] = (prefix[j] - prefix[i - 1] + MOD) % MOD;
            } else {
                dp[j + 1] = prefix[j] % MOD;
            }
            prefix[j + 1] = prefix[j] + dp[j + 1] % MOD;
        }

        return dp[n];
    }
};
