class Solution {
    public int longestSubsequence(String s, int k) {
        int n = s.length(), length = 0;
        int powerVal = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                length++;
            } else if (powerVal <= k) {
                k = k - powerVal;
                length++;
            }
            if (powerVal <= k) {
                powerVal *= 2; // powerVal <<= 1;
            }
        }
        return length;
    }
}
