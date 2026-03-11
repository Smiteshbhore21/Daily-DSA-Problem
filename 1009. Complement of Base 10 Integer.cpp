class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int result = 0;
        int cntBits = __builtin_popcount(n);
        int currActiveBits = 0;
        for (int bit = 0; bit <= 31; bit++) {
            if (currActiveBits == cntBits)
                break;
            if ((n & (1 << bit)) == 0) {
                result = result + (1 << bit);
            } else {
                currActiveBits++;
            }
        }
        return result;
    }
};
