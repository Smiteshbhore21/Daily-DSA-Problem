class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<long long> diff(n, 0);

        int minVal = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {

            diff[max(0, i - r)] += stations[i];
            if (i + r + 1 < n)
                diff[i + r + 1] -= stations[i];

            sum += stations[i];
            minVal = min(minVal, stations[i]);
        }

        long long low = minVal;
        long long high = sum + k;
        long long result = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, diff, r, k, n)) {
                low = mid + 1;
                result = mid;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    bool check(long long& mid, vector<long long> diff, int r, int k, int n) {
        long long cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];

            if (cumSum < mid) {
                long long need = mid - cumSum;
                if (need > k) {
                    return false;
                }

                k -= need;
                cumSum += need;
                if (i + 2 * r + 1 < n)
                    diff[i + 2 * r + 1] -= need;
            }
        }
        return true;
    }
};
