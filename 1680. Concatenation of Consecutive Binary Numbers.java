class Solution {
    public static final int MOD = 1_000_000_007;

    public int concatenatedBinary(int n) {
        int digits = 0;
        long result = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0)
                digits++;
            result = (((result << digits) % MOD) + i) % MOD;
        }
        return (int) result;
    }
}

// class Solution {
//     public static final int MOD = 1_000_000_007;
//     public int concatenatedBinary(int n) {
//         long result = 0;
//         for (int i = 1; i <= n; i++) {
//             int toShift = 32 - Integer.numberOfLeadingZeros(i);
//             result = (((result << toShift) % MOD) + i) % MOD;
//         }
//         return (int)result;
//     }
// }
