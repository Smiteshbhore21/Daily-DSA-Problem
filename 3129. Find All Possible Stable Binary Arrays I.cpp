// TC --> O(Zero∗One∗Limit)
int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int t[201][201][2];
        // t[onesLeft][zerosLeft][lastWasOne];
        t[0][0][0] = t[0][0][1] = 1;

        for (int oneLeft = 0; oneLeft <= one; oneLeft++) {
            for (int zeroLeft = 0; zeroLeft <= zero; zeroLeft++) {
                if (oneLeft == 0 && zeroLeft == 0)
                    continue;
                int result = 0;
                for (int len = 1; len <= min(zeroLeft, limit); len++) {
                    result = (result + t[oneLeft][zeroLeft - len][0]) % MOD;
                }
                t[oneLeft][zeroLeft][1] = result;
                result = 0;
                for (int len = 1; len <= min(oneLeft, limit); len++) {
                    result = (result + t[oneLeft - len][zeroLeft][1]) % MOD;
                }
                t[oneLeft][zeroLeft][0] = result;
            }
        }
        return (t[one][zero][0] + t[one][zero][1]) % MOD;
    }
};

// Recursion
// int MOD = 1e9 + 7;
// class Solution {
//     int t[201][201][2];
// public:
//     int numberOfStableArrays(int zero, int one, int limit) {
//         memset(t, -1, sizeof(t));
//         return (solve(one, zero, false, limit) +
//                 solve(one, zero, true, limit)) %
//                MOD;
//     }
//     int solve(int oneLeft, int zeroLeft, bool lastWasOne, int limit) {
//         if (oneLeft == 0 && zeroLeft == 0)
//             return 1;
//         if (t[oneLeft][zeroLeft][lastWasOne] != -1)
//             return t[oneLeft][zeroLeft][lastWasOne];
//         int result = 0;
//         if (lastWasOne)
//             for (int len = 1; len <= min(limit, zeroLeft); len++) {
//                 result =
//                     (result + solve(oneLeft, zeroLeft - len, false, limit)) %
//                     MOD;
//             }
//         else
//             for (int len = 1; len <= min(limit, oneLeft); len++) {
//                 result =
//                     (result + solve(oneLeft - len, zeroLeft, true, limit)) %
//                     MOD;
//             }
//         return t[oneLeft][zeroLeft][lastWasOne] = result;
//     }
// };
