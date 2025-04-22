class Solution {
public:
    int M = 1e9 + 7;

    void findSets(int m, vector<int>& count, vector<vector<int>>& dp) {
        if (dp[m][1] != 0)
            return;
        dp[m][1] = 1;
        count[1]++;
        for (int div = 2; div <= m; div++) {
            if (m % div == 0) {
                findSets(m / div, count, dp);
                for (int len = 1; len < 15; len++) {
                    if (dp[m / div][len] != 0) {
                        dp[m][len + 1] += dp[m / div][len];
                        count[len + 1] += dp[m / div][len];
                    }
                }
            }
        }
    }

    int findPower(long long a, long long b) {
        if (b == 0)
            return 1;
        long long half = findPower(a, b / 2);
        long long result = (half * half) %M;
        if (b % 2 == 1)
            result = (result * a) % M;
        return result;
    }

    int modularnCr(int n, int r, vector<long long>& fact) {
        if (r < 0 || r > n)
            return 0;
        long long b = (fact[r] * fact[n - r]) % M;
        return (fact[n] * findPower(b, M - 2)) % M;
    }

    int idealArrays(int n, int maxVal) {
        vector<vector<int>> dp(maxVal + 1, vector<int>(15, 0));
        vector<int> count(15, 0);

        for (int val = 1; val <= maxVal; val++) {
            findSets(val, count, dp);
        }

        vector<long long> fact(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % M;
        }

        long long result = 0;
        for (int len = 1; len < 15; len++) {
            if(n < len) break;
            if (count[len] != 0) {
                long long possibilities = modularnCr(n - 1, len - 1, fact);

                result = (result + (count[len] * possibilities) % M) % M;
            }
        }
        return (int)result;
    }
};

// TLE ---->
//  class Solution {
//  public:
//      int M = 1e9 + 7;

//     int solve(int start, int count, int n, int maxVal) {
//         if (count == n)
//             return 1;
//         long long res = 0;
//         for (int multi = 1; start * multi <= maxVal; multi++) {
//             res = (res + solve(start * multi, count + 1, n, maxVal)) % M;
//         }
//         return res;
//     }

//     int idealArrays(int n, int maxValue) {
//         long long res = 0;

//         for (int startVal = 1; startVal <= maxValue; startVal++) {
//             res = (res + solve(startVal, 1, n, maxValue)) % M;
//         }
//         return res;
//     }
// };

// TLE ---->
// class Solution {
// public:
//     int M = 1e9 + 7;
//     vector<vector<int>> t;

//     int solve(int start, int count, int n, int maxVal) {
//         if (count == n)
//             return 1;
//         if (t[start][count] != -1)
//             return t[start][count];
//         long long res = 0;
//         for (int multi = 1; start * multi <= maxVal; multi++) {
//             res = (res + solve(start * multi, count + 1, n, maxVal)) % M;
//         }
//         return t[start][count] = res;
//     }

//     int idealArrays(int n, int maxValue) {
//         long long res = 0;
//         t.resize(maxValue + 1, vector<int>(n + 1, -1));

//         for (int startVal = 1; startVal <= maxValue; startVal++) {
//             res = (res + solve(startVal, 1, n, maxValue)) % M;
//         }
//         return res;
//     }
// };
