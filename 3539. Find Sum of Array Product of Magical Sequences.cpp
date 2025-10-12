int MOD = 1e9 + 7;
using ll = long long;
class Solution {
public:
    int C[31][31] = {{0}};
    int dp[31][31][50][31];
    void precompute() {
        if (C[0][0] == 1)
            return;
        for (int i = 1; i <= 30; i++) {
            C[i][0] = 1, C[i][i] = 1;
            for (int j = 1; j <= i / 2; j++) {
                int iCj = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] = iCj;
                C[i][i - j] = iCj;
            }
        }
    }

    ll func(int m_rem, int k_rem, int i, int mask, vector<int> nums) {
        int cnt = __builtin_popcount(mask);
        if (m_rem < 0 || k_rem < 0 || m_rem + cnt < k_rem)
            return 0;

        if (m_rem == 0) {
            if (k_rem == cnt)
                return 1;
            return 0;
        }

        if (i >= nums.size())
            return 0;

        if (dp[m_rem][k_rem][i][mask] != -1)
            return dp[m_rem][k_rem][i][mask];

        int x = nums[i];
        int exp = 1;
        ll ans = 0;
        for (int f = 0; f <= m_rem; f++) {
            ll mul = (1ll * C[m_rem][f] * exp) % MOD;
            int newMask = mask + f;
            int next = newMask >> 1;
            int isset = newMask & 1;
            exp = (1ll * exp * x) % MOD;
            ans = (ans +
                   (mul * func(m_rem - f, k_rem - isset, i + 1, next, nums))) %
                  MOD;
        }
        return dp[m_rem][k_rem][i][mask] = ans;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        precompute();
        memset(dp, -1, sizeof(dp));
        return func(m, k, 0, 0, nums);
    }
};
