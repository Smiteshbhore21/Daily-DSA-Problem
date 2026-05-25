class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> t(n, 0);
        t[0] = 1;
        int count = 0;
        for (int j = 1; j < n; j++) {

            if (j - minJump >= 0)
                count += t[j - minJump];

            if (j - maxJump - 1 >= 0)
                count -= t[j - maxJump - 1];

            if (count > 0 && s[j] == '0')
                t[j] = 1;
        }

        return t[n - 1] > 0;
    }
};

// Bottom Up -->
// class Solution {
// public:
//     bool canReach(string s, int minJump, int maxJump) {
//         int n = s.size();
//         vector<int> dp(n, 0);
//         dp[n - 1] = true;
//         for (int i = n - 1; i >= 0; i--) {
//             for (int jump = minJump; jump <= maxJump; jump++) {
//                 int j = i + jump;
//                 if (j >= n)
//                     break;
//                 if (s[j] == '0' && dp[j]) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[0];
//     }
// };

// TLE O(N * (maxJump - minJump)) -->
// class Solution {
// public:
//     int n;
//     int minJ, maxJ;
//     vector<int> memo;
//     bool canReach(string s, int minJump, int maxJump) {
//         n = s.size();
//         memo.assign(n, -1);
//         minJ = minJump;
//         maxJ = maxJump;
//         return solve(0, s);
//     }
//     bool solve(int i, string& s) {
//         if (memo[i] != -1)
//             return memo[i];
//         if (i == n - 1)
//             return true;
//         for (int j = i + minJ; j <= min(i + maxJ, n - 1); j++) {
//             if (j >= n)
//                 return memo[i] = false;
//             if (s[j] == '0' && solve(j, s))
//                 return memo[i] = true;
//         }
//         return memo[i] == false;
//     }
// };
