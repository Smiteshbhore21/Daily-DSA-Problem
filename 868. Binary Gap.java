class Solution {
    public int binaryGap(int n) {
        int prev = Integer.MAX_VALUE;
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = (n & (1 << i)) == 0 ? 0 : 1;
            if (bit == 1) {
                result = Math.max(result, i - prev);
                prev = i;
            }
        }
        return result;
    }
}
