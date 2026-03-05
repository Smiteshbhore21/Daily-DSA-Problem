class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int toChange1 = 0;
        int toChange2 = 0;
        for (int i = 0; i < n; i++) {
            char ch1 = (i % 2 == 0) ? '0' : '1';
            char ch2 = (i % 2 == 0) ? '1' : '0';
            if (s[i] != ch1)
                toChange1++;
            if (s[i] != ch2)
                toChange2++;
        }
        return min(toChange1, toChange2);
    }
};
