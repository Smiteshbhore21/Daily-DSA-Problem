using ll = long long;
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        ll result = -1;

        ll l = 1;
        ll r = (ll)(*max_element(coins.begin(), coins.end())) * k;

        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (countSmaller(mid, coins) >= k) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }

    ll countSmaller(ll mid, vector<int>& coins) {
        ll correctedCoins = 0;
        int n = coins.size();

        for (int expressions = 1; expressions <= (1 << n) - 1; expressions++) {
            ll lcm = 0;
            ll order = 0;

            for (int i = 0; i < n; i++) {
                if (expressions & (1 << i)) {
                    order++;

                    if (lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            if (order % 2 == 0) {
                correctedCoins -= mid / lcm;
            } else {
                correctedCoins += mid / lcm;
            }
        }

        return correctedCoins;
    }
};
