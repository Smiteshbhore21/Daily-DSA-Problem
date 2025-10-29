class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;
        for (int i = 0; i <= 32; i++) {
            ans = ans | (1 << i);
            if (ans >= n)
                return ans;
        }
        return 0;
    }
};
