int MOD = 1e9 + 7;
class Solution {
public:
    int numOfWays(int n) {
        long long diff = 6, same = 6;

        for (int i = 1; i < n; i++) {
            long long s = (3 * same + 2 * diff) % MOD;
            long long d = (2 * same + 2 * diff) % MOD;

            same = s;
            diff = d;
        }

        return (same + diff) % MOD;
    }
};

// O(N) -->
// int MOD = 1e9 + 7;
// class Solution {
// public:
//     vector<string> rowStates;
//     vector<vector<int>> memo;
//     void generateRowStates(string curr, char prevChar, int l) {
//         if (l == 3) {
//             rowStates.push_back(curr);
//             return;
//         }
//         for (char color : {'R', 'Y', 'G'}) {
//             if (color != prevChar)
//                 generateRowStates(curr + color, color, l + 1);
//         }
//     }
//     int numOfWays(int n) {
//         generateRowStates("", '#', 0);
//         memo.resize(n + 1, vector<int>(13, -1));
//         int result = 0;
//         for (int i = 0; i < 12; i++) {
//             result = (result + solve(n - 1, i)) % MOD;
//         }
//         return result;
//     }
//     int solve(int remainRow, int prevIdx) {
//         if (remainRow == 0)
//             return 1;
//         if (memo[remainRow][prevIdx] != -1)
//             return memo[remainRow][prevIdx];
//         int ways = 0;
//         string prevState = rowStates[prevIdx];
//         for (int i = 0; i < rowStates.size(); i++) {
//             if (i == prevIdx)
//                 continue;
//             string currState = rowStates[i];
//             bool valid = true;
//             for (int j = 0; j < 3; j++) {
//                 if (prevState[j] == currState[j]) {
//                     valid = false;
//                     break;
//                 }
//             }
//             if (valid) {
//                 ways = (ways + solve(remainRow - 1, i)) % MOD;
//             }
//         }
//         return memo[remainRow][prevIdx] = ways;
//     }
// };
