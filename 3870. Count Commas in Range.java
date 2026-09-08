// O(1) -->
class Solution {
    public int countCommas(int n) {
        if (n < 1000)
            return 0;
        return n - 999;
    }
}

// O(log(n)) -->
// class Solution {
//     public int countCommas(int n) {
//         int digitCnt = digitCount(n);
//         if (digitCnt < 4)
//             return 0;
//         return n - 999;
//     }
//     public int digitCount(int n) {
//         int cnt = 0;
//         while (n != 0) {
//             cnt++;
//             n /= 10;
//         }
//         return cnt;
//     }
// }
