class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        int t = 0;
        while (t <= 36) {
            long long val = num1 - (t * num2);
            if (val < 0)
                return -1;
            if (__builtin_popcountll(val) <= t && t <= val) {
                return t;
            }
            t++;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int makeTheIntegerZero(long long num1, long long num2) {
//         int t = 0;
//         while (true) {
//             long long val = num1 - (t * num2);
//             if (val < 0)
//                 return -1;
//             if (__builtin_popcountll(val) <= t && t <= val) {
//                 return t;
//             }
//             t++;
//         }
//         return -1;
//     }
// };
