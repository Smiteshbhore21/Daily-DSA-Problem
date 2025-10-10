class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int* dp = new int[n](0);
        int* ans = new int(INT_MIN);
        for (int i = n - 1; i >= 0; i--) {
            if ((i + k) < n) {
                dp[i] = dp[(i + k)] + energy[i];
            } else {
                dp[i] = energy[i];
            }
            *ans = max(dp[i], *ans);
        }
        delete[] dp;
        return *ans;
    }
};
