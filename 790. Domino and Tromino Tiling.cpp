class Solution {
public:
    int t[1001];
    int M = 1e9 + 7;
    int numTilings(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
    int solve(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;
        if (t[n] != -1)
            return t[n];

        return t[n] = (2 * solve(n - 1) % M + solve(n - 3) % M) % M;
    }
};

// class Solution {
// public:
//     int numTilings(int n) {
//         if (n == 1)
//             return 1;
//         if (n == 2)
//             return 2;
//         if (n == 3)
//             return 5;
//         long long a = 1, b = 2, c = 5;
//         int MOD = 1e9 + 7;
//         for (int i = 4; i <= n; i++) {
//             long long temp = c;
//             c = ((2 * temp) + a) % MOD;
//             a = b;
//             b = temp;
//         }
//         return c;
//     }
// };
