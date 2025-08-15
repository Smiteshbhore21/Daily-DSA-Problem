class Solution {
    public boolean isPowerOfFour(int n) {
        return (n & (n - 1)) == 0 && n % 3 == 1;
    }
}

// class Solution {
//     public boolean isPowerOfFour(int n) {
//         if (n <= 0)
//             return false;
//         int bitC = Integer.bitCount(n);
//         if (bitC != 1)
//             return false;
//         int zeroBitC = 0;
//         for (int i = 0; i < 32; i++) {
//             if ((n & (1 << i)) == 0) {
//                 zeroBitC++;
//             } else {
//                 break;
//             }
//         }
//         return zeroBitC % 2 == 0;
//     }
// }
