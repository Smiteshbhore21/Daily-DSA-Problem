class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= (n / 2); i++) {
            if (isSafe(i) && isSafe(n - i)) {
                return {i, n - i};
            }
        }
        return {};
    }
    bool isSafe(int a) {
        while (a) {
            if (a % 10 == 0)
                return false;
            a /= 10;
        }
        return true;
    }
};
