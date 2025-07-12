class Solution {
public:
    int N = 0, f = 0, s = 0;
    int minVal = INT_MAX, maxVal = INT_MIN;
    void solve(int mask, int round, int i, int j) {
        if (this->f == i && this->s == j) {
            maxVal = max(maxVal, round);
            minVal = min(minVal, round);
            return;
        }
        if (i >= j) {
            solve(mask, round + 1, 0, N);
        } else if ((mask & (1 << i)) == 0) {
            solve(mask, round, i + 1, j);
        } else if ((mask & (1 << j)) == 0) {
            solve(mask, round, i, j - 1);
        } else {
            if (i != f && i != s) {
                solve(mask ^ (1 << i), round, i + 1, j - 1);
            }
            if (j != f && j != s) {
                solve(mask ^ (1 << j), round, i + 1, j - 1);
            }
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N = n - 1, f = firstPlayer - 1, s = secondPlayer - 1;
        solve((1 << n) - 1, 1, 0, n - 1);
        return {minVal, maxVal};
    }
};
