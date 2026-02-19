class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int n = s.length();
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                curr++;
            else {
                result += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        result += min(prev, curr);
        return result;
    }
};
