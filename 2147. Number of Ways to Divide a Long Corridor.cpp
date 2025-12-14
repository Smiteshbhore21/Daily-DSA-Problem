int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int count = 0;
        int seat = 0;
        int result = 1;
        for (const char ch : corridor) {
            if (ch == 'S') {
                seat++;
            }
            if (seat == 2) {
                count++;
            }
            if (seat == 3) {
                result = (result * 1ll * count) % MOD;
                count = 0;
                seat = 1;
            }
        }
        if (seat != 2) {
            return 0;
        }
        return result;
    }
};
