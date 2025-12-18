using ll = long long;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll maxi = 0;
        int n = prices.size();
        vector<ll> prefix(n + 1, 0), prefixProfit(n + 1, 0);
        for (int i = 0; i < n; i++) {
            maxi += prices[i] * strategy[i];
            prefix[i + 1] = prices[i];
            prefix[i + 1] += prefix[i];

            prefixProfit[i + 1] = prices[i] * strategy[i];
            prefixProfit[i + 1] += prefixProfit[i];
        }

        for (int i = k; i <= n; i++) {
            // [i - k + 1, k] WINDOW
            ll ans = prefixProfit[n] - (prefixProfit[i] - prefixProfit[i - k]);
            ans += (prefix[i] - prefix[i - k / 2]);
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};
