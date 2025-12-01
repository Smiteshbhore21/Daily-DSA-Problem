class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        long long l = 0;
        for (const int& battery : batteries) {
            sum += battery;
            l = min(l, (long long)battery);
        }
        long long r = sum / n;
        long long result = 0;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (possible(batteries, mid, n)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }

    bool possible(vector<int>& batteries, long long& mid, int& n) {
        long long target_mints = n * mid;
        long long sum = 0;
        for (int i = 0; i < batteries.size(); i++) {
            sum += min(mid, (long long)batteries[i]);
            if (sum >= target_mints)
                return true;
        }
        return false;
    }
};
