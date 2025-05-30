class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto minMax = minmax_element(ranks.begin(), ranks.end());
        long long start = *minMax.first,
                  end = (*minMax.second) * (cars * 1ll) * (1ll * cars), ans = 0;
        while (start <= end) {
            long long temp = 0, mid = start + (end - start) / 2;
            for (int& x : ranks) {
                temp += 1ll * (sqrt((1.0 * mid) / x));
            }
            if (temp >= cars) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
