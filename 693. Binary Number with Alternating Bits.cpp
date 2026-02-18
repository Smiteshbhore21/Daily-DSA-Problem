class Solution {
public:
    bool hasAlternatingBits(int n) {
        int res = n & (1 << 0);
        for (int i = 1; i < 32; i++) {
            int prevBit = (n & (1 << (i - 1))) == 0 ? 0 : 1;
            int curBit = (n & (1 << i)) == 0 ? 0 : 1;
            if (prevBit == curBit) {
                return false;
            }
            res = res | (curBit << i);
            if (res == n)
                break;
        }
        return true;
    }
};
