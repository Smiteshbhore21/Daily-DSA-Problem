using ll = long long;
int M = 1e9 + 7;
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<ll> nonZeroCnt(n, 0), numberUpto(n, 0), digitSumUpTo(n, 0),
            pow10(n + 1, 0);

        pow10[0] = 1;

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        nonZeroCnt[0] = (s[0] != '0') ? 1 : 0;
        numberUpto[0] = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCnt[i] = nonZeroCnt[i - 1] + ((0 != digit) ? 1 : 0);

            if (digit != 0) {
                numberUpto[i] = ((numberUpto[i - 1] * 10) + digit) % M;
            } else {
                numberUpto[i] = numberUpto[i - 1];
            }

            digitSumUpTo[i] = digitSumUpTo[i - 1] + digit;
        }


        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCnt[l - 1];
            ll numBefore = (l == 0) ? 0 : numberUpto[l - 1];

            int endCount = nonZeroCnt[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                result[i] = 0;
                continue;
            }

            ll x =
                (numberUpto[r] - (numBefore * pow10[subStrLen] % M) + M) %
                M;
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((x * sum) % M);
        }

        return result;
    }
};
