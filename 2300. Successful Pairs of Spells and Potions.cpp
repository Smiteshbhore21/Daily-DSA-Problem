class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> pairs;
        for (int& x : spells) {
            long long multiple = searchMultiplier(x, success);
            auto it = lower_bound(potions.begin(), potions.end(), multiple);
            if (it != potions.end()) {
                int count = (int)(potions.end() - it);
                pairs.push_back(count);
            } else {
                pairs.push_back(0);
            }
        }
        return pairs;
    }

    long long searchMultiplier(int& sp, long long& success) {
        long long l = 1, r = success;
        long long mid = 0, prevVal = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (mid * sp >= success) {
                prevVal = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return prevVal;
    }
};
