class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int countNum2 = 0;
        while (num2 > 0) {
            num2 = num2 & (num2 - 1);
            countNum2++;
        }
        int bit = 31;
        int ans = 0;
        while (bit >= 0 && countNum2 > 0) {
            if ((num1 & (1 << bit)) != 0) {
                ans = ans | (1 << bit);
                countNum2--;
            }
            bit--;
        }
        bit = 0;
        while (countNum2 > 0 && bit <= 32) {
            if ((num1 & (1 << bit)) == 0) {
                ans = ans | (1 << bit);
                countNum2--;
            }
            bit++;
        }
        return ans;
    }
};
