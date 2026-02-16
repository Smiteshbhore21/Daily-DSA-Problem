class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int idx = 31;
        for (int i = 0; i < 32; i++) {
            int bit = (n & (1 << i)) == 0 ? 0 : 1;
            ans = ans | (bit << idx);
            idx--;
        }
        return ans;
    }
};
