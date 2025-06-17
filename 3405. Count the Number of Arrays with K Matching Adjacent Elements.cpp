using ll = long long;
int MOD = 1e9 + 7;
vector<int> fact, inv_fact;
class Solution {
    int binaryExp(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return res;
    }
    int MMI(int val) { return binaryExp(val, MOD - 2); }
    void inverseFact(const int& n) {
        inv_fact = vector<int>(n + 1);
        inv_fact[n] = MMI(fact[n]);
        for (int i = n; i > 0; i--)
            inv_fact[i - 1] = (1ll * inv_fact[i] * i) % MOD;
    }
    void factorial(const int& n) {
        fact = vector<int>(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = (1ll * fact[i - 1] * i) % MOD;
    }
    void preCompute(const int& n) {
        factorial(n);
        inverseFact(n);
    }

public:
    int countGoodArrays(int n, int m, int k) {
        preCompute(n);
        int run_ways =
            ((1ll * fact[n - 1] * inv_fact[n - k - 1]) % MOD * inv_fact[k]) %
            MOD;
        int ways_to_assign = (1ll * m * binaryExp(m - 1, n - k - 1)) % MOD;
        return (1ll * run_ways * ways_to_assign) % MOD;
    }
};

// int MOD = 1e9 + 7;
// using ll = long long;
// class Solution {
//     int binaryExp(ll a, ll b) {
//         if (b == 0)
//             return 1;
//         ll half = binaryExp(a, b / 2);
//         ll res = (half * half) % MOD;
//         if (b % 2 == 1)
//             res = (res * a) % MOD;
//         return res;
//     }

//     ll modularnCr(int n, int r, vector<ll>& fact, vector<ll>& inv_fact) {
//         return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
//     }

// public:
//     int countGoodArrays(int n, int m, int k) {
//         vector<ll> factorial(n + 1, 1);
//         for (int i = 2; i <= n; i++) {
//             factorial[i] = (factorial[i - 1] * i) % MOD;
//         }

//         vector<ll> inv_fact(n + 1, 1);
//         for (int i = 0; i <= n; i++) {
//             inv_fact[i] = binaryExp(factorial[i], MOD - 2);
//         }
//         ll res = modularnCr(n - 1, k, factorial, inv_fact);
//         res = (res * m) % MOD;
//         res = (res * binaryExp(m - 1, n - k - 1)) % MOD;
//         return res;
//     }
// };
