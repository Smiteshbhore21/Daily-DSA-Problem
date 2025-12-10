int MOD = 1e9 + 7;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int result = 1;
        for (int i = 1; i < n; i++) {
            if (complexity[0] >= complexity[i]) {
                return 0;
            }
            result = (1ll * result * i) % MOD;
        }
        return result;
    }
};
