class Solution {
public:
    vector<int> memo;
    int rotatedDigits(int n) {
        int result = 0;
        memo.resize(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (solve(i) == 1) {
                result++;
            }
        }
        return result;
    }
    int solve(int num) {
        if (memo[num] != -1)
            return memo[num];

        if (num == 0)
            return 0;
        int remain = solve(num / 10);
        int digit = num % 10;
        int digit_check;
        if (digit == 0 || digit == 1 || digit == 8)
            digit_check = 0;
        else if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
            digit_check = 1;
        else
            return memo[num] = 2;
        if (remain == 2)
            return memo[num] = 2;
        if (remain == 0 && digit_check == 0)
            return memo[num] = 0;
        return memo[num] = 1;
    }
};

// Number Slice -->
// class Solution {
// public:
//     int rotatedDigits(int n) {
//         int result = 0;
//         for (int i = 1; i <= n; i++) {
//             if (isGood(i)) {
//                 result++;
//             }
//         }
//         return result;
//     }
//     bool isGood(int num) {
//         bool changed = false;
//         while (num) {
//             int digit = num % 10;
//             if (digit == 3 || digit == 4 || digit == 7) {
//                 return false;
//             }
//             if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
//                 changed = true;
//             }
//             num /= 10;
//         }
//         return changed;
//     }
// };

// String -->
// class Solution {
// public:
//     int rotatedDigits(int n) {
//         int result = 0;
//         for (int i = 1; i <= n; i++) {
//             int rot = rotate180(i);
//             if (rot != i) {
//                 result++;
//             }
//         }
//         return result;
//     }
//     int rotate180(int num) {
//         string str = to_string(num);
//         int rot = 0;
//         for (char& ch : str) {
//             if (ch == '3' || ch == '4' || ch == '7') {
//                 return num;
//             }
//             if (ch == '2') {
//                 rot = (rot * 10) + 5;
//             } else if (ch == '5') {
//                 rot = (rot * 10) + 2;
//             } else if (ch == '6') {
//                 rot = (rot * 10) + 9;
//             } else if (ch == '9') {
//                 rot = (rot * 10) + 6;
//             } else if (ch == '0' || ch == '1' || ch == '8') {
//                 rot = (rot * 10) + (ch - '0');
//             }
//         }
//         return rot == 0 ? num : rot;
//     }
// };
