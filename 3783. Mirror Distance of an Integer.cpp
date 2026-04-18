class Solution {
public:
    int mirrorDistance(int n) { return abs(n - reverse(n)); }
    int reverse(int n) {
        int rev = 0;
        while (n) {
            rev = (rev * 10) + n % 10;
            n /= 10;
        }
        return rev;
    }
};
