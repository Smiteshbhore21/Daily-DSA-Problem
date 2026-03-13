class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());
        long long l = 1;
        long long r = (long long)maxTime * mountainHeight * (mountainHeight + 1) / 2;

        long long result = 0;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (check(mid, mountainHeight, workerTimes)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }

    bool check(const long long& mid, const int& mountainHeight,
               vector<int>& workerTimes) {
        long long h = 0;
        for (int& t : workerTimes) {
            h += (long long)(sqrt(2.0 * mid / t + 0.25) - 0.5);

            if (h >= mountainHeight) {
                return true;
            }
        }
        return h >= mountainHeight;
    }
};
