class Solution {
    private int m, n;

    private int[][] dp;

    public int minimumDeleteSum(String s1, String s2) {
        m = s1.length();
        n = s2.length();
        dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; ++i)
            Arrays.fill(dp[i], -1);
        return solve(s1, s2, 0, 0);
    }

    private int solve(String s1, String s2, int i, int j) {
        if (i >= m && j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i >= m) {
            dp[i][j] = s2.charAt(j) + solve(s1, s2, i, j + 1);
            return dp[i][j];
        }

        if (j >= n) {
            dp[i][j] = s1.charAt(i) + solve(s1, s2, i + 1, j);
            return dp[i][j];
        }

        if (s1.charAt(i) == s2.charAt(j)) {
            dp[i][j] = solve(s1, s2, i + 1, j + 1);
            return dp[i][j];
        }

        int delete_s1_i = s1.charAt(i) + solve(s1, s2, i + 1, j);
        int delete_s2_j = s2.charAt(j) + solve(s1, s2, i, j + 1);

        dp[i][j] = Math.min(delete_s1_i, delete_s2_j);

        return dp[i][j];
    }
}

// MLE(CPP) -->
// class Solution {
// public:
//     unordered_set<string> set1, set2;
//     int sumASCII(const string& s) {
//         int sum = 0;
//         for (const char& str : s) {
//             sum += str;
//         }
//         return sum;
//     }
//     int minimumDeleteSum(string s1, string s2) {
//         int totalSum1 = 0, totalSum2 = 0;
//         for (const char& s : s1) {
//             totalSum1 += s;
//         }
//         for (const char& s : s2) {
//             totalSum2 += s;
//         }
//         perCom(1, s1, "", 0);
//         perCom(2, s2, "", 0);
//         int bestSum = 0;
//         if (set1.size() > set2.size()) {
//             for (string s : set1) {
//                 int asciiSum = sumASCII(s);
//                 if (set2.count(s) && asciiSum > bestSum) {
//                     bestSum = asciiSum;
//                 }
//             }
//         } else {
//             int totalSum = 0;
//             for (string s : set2) {
//                 int asciiSum = sumASCII(s);
//                 if (set1.count(s) && asciiSum > bestSum) {
//                     bestSum = asciiSum;
//                 }
//             }
//         }
//         return totalSum1 + totalSum2 - (2 * bestSum);
//     }
//     void perCom(const int& type, string& s, string curr, int i) {
//         if (i == s.size()) {
//             if (type == 1)
//                 set1.insert(curr);
//             else
//                 set2.insert(curr);
//             return;
//         }
//         perCom(type, s, curr + s[i], i + 1);
//         perCom(type, s, curr, i + 1);
//     }
// };
