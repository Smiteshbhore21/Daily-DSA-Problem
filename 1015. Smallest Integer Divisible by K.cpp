class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int rem = 0;
        int digitCnt = 1;
        while (digitCnt <= k) {
            rem = ((rem * 10) + 1) % k;
            if (rem == 0)
                return digitCnt;
            digitCnt++;
        }
        return -1;
    }
};
