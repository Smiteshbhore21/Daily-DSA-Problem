class Solution {
public:
    int nextBeautifulNumber(int n) {
        n++;
        while (true) {
            if (isBalanced(n))
                break;
            n++;
        }
        return n;
    }
    bool isBalanced(int n) {
        int freq[10] = {0};
        while (n) {
            freq[n % 10]++;
            n /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (freq[i] != 0 && i != freq[i])
                return false;
        }
        return true;
    }
};
