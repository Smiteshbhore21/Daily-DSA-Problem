int M = 1e9 + 7;
class Solution {
public:
    int t[301][301];
    int binaryExpo(int a, int b) {
        if (b == 0)
            return 1;
        int half = binaryExpo(a, b / 2);
        int res = (half * half) % M;
        if (b & 1) {
            res = (res * a) % M;
        }
        return res;
    }

    int solve(int x, int num, int n) {
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        int currPowerValue = binaryExpo(num, x);
        if (currPowerValue > n)
            return 0;

        if (t[n][num] != -1)
            return t[n][num];

        int take = solve(x, num + 1, n - currPowerValue);
        int skip = solve(x, num + 1, n);

        return t[n][num] = (take + skip) % M;
    }

    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(x, 1, n);
    }
};
