class Solution {
    public long flowerGame(long n, long m) {
        // (odd * even) + (even * odd)
        return ((n + 1) / 2) * (m / 2) + (n / 2) * ((m + 1) / 2);
    }
}
