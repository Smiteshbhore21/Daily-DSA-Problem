// Bottom Up -->
int M = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> t(n + 1);
        t[1] = 1;
        long long count = 0;
        for (int day = 2; day <= n; day++) {
            if (day - delay > 0) {
                count = (count + t[day - delay]) % M;
            }
            if (day - forget > 0) {
                count = (count - t[day - forget] + M) % M;
            }
            t[day] = count;
        }

        int result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                result = (result + t[day]) % M;
            }
        }
        return result;
    }
};

// Recursion + Memo ->
// int M = 1e9 + 7;
// class Solution {
// public:
//     vector<int> t;
//     int solve(int day, int delay, int forget) {
//         if (day == 1)
//             return 1;
//         if (t[day] != -1)
//             return t[day];
//         int result = 0;
//         for (int prev = day - forget + 1; prev <= day - delay; prev++) {
//             if (prev > 0)
//                 result = (result + solve(prev, delay, forget)) % M;
//         }
//         return t[day] = result;
//     }
//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         int total = 0;
//         t.assign(n + 1, -1);
//         for (int d = n - forget + 1; d <= n; d++) {
//             if (d > 0) {
//                 total = (total + solve(d, delay, forget)) % M;
//             }
//         }
//         return total;
//     }
// };
