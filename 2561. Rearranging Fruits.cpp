// O(nlog(n)) --> 
using ll = long long;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp1, mp2, both;
        size_t n = basket1.size();
        for (int i = 0; i < n; i++) {
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
            both[basket1[i]]++;
            both[basket2[i]]++;
        }
        vector<int> toSwap1, toSwap2;
        int globalMin = INT_MAX;
        for (auto [x, y] : both) {
            globalMin = min(globalMin, x);
            if (y % 2 == 1)
                return -1ll;
            if (mp1[x] == (y / 2))
                continue;
            if (mp1[x] > (y / 2)) {
                for (int i = 0; i < abs(mp1[x] - both[x] / 2); i++) {
                    toSwap1.push_back(x);
                }
            }
            if (mp2[x] > (y / 2)) {
                for (int i = 0; i < abs(mp2[x] - both[x] / 2); i++) {
                    toSwap2.push_back(x);
                }
            }
        }
        sort(toSwap1.begin(), toSwap1.end());
        sort(toSwap2.begin(), toSwap2.end());
        long long minCost = 0;
        n = toSwap1.size();
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            minCost += min(min(toSwap1[i], toSwap2[j]), globalMin * 2);
        }
        return minCost;
    }
};
